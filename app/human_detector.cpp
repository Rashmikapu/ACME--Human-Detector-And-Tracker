#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <../include/my_robot.hpp>

#include <opencv2/highgui.hpp>

perception::HumanDetector::HumanDetector() {
  input_height = 640.0;
  input_width = 640.0;
}
cv::dnn::Net perception::HumanDetector::YoloModel() {
  // std::vector<std::string> class_list;
  // frame = frame1;
  class_list.push_back("person");
  // std::vector<std::string> class_list1;
  // std::ifstream ifs("coco.names");
  // std::string line;

  // while (getline(ifs, line)) {
  //   class_list1.push_back(line);
  // }
  // std::cout<<"Class list in preprocess: "<<class_list.size();
  net = cv::dnn::readNet("/home/rashmikapu/Desktop/808x/midterm/Human-Detector-And-Tracker/models/yolov5s.onnx");
  return net;
}

std::vector<cv::Mat> perception::HumanDetector::preProcess(
    cv::Mat &input, cv::dnn::Net &model) {
  cv::Mat blob;  // Create a matrix called blob
  std::cout << "Input dimensions: " << input.size() << std::endl;
  std::cout << "Input data type: " << input.type() << std::endl;

  // Size is to represent the desired image blob size
  // Scalar() is for mean subtraction
  // true : This indicates that the input image should be considered in BGR
  // (Blue, Green, Red) order. false : This parameter specifies whether the
  // input image data should be swapped. If set to true, the Red and Blue
  // channels will be swapped
  cv::dnn::blobFromImage(input, blob, 1.0 / 255.0,
                         cv::Size(input_width, input_height), cv::Scalar(),
                         true, false);
  // std::cout << "Blob dimensions: " << blob.size() << std::endl;
  // std::cout << "Blob data type: " << blob.type() << std::endl;
  model.setInput(blob);
  std::vector<cv::Mat> outputs;
  
  model.forward(outputs, model.getUnconnectedOutLayersNames());
  // std::cout<<"outputs:"<<std::endl<<outputs[0].size();
  return outputs;
  // std::vector<cv::Mat> detections(10, cv::Mat());
  // return detections;
}

cv::Mat perception::HumanDetector::postProcess(
    cv::Mat &input_image, std::vector<cv::Mat> &detections) {
  perception::Visualization viz;
  std::vector<int> class_ids;
  std::vector<float> confidences;
  std::vector<cv::Rect> boxes;
  // std::cout<<"Input image"<<input_image.rows<<input_image.cols;
  // Resizing factor.
  float x_factor = input_image.cols / input_width;
  float y_factor = input_image.rows / input_height;

  float *data = (float *)detections[0].data;

  const int dimensions = 85;
  const int rows = 25200;
  // Iterate through 25200 detections.
  for (int i = 0; i < rows; ++i)
  {
      float confidence = data[4];
      // std::cout<<"confidence: "<<confidence;
      // Discard bad detections and continue.
      if (confidence >= CONFIDENCE_THRESHOLD)
      {
          // std::cout<<"Inside confidence if";
          float * classes_scores = data + 5;
          // Create a 1x85 Mat and store class scores of 80 classes.
          // std::cout<<"Class list size:"<<class_list.size();
          cv::Mat scores(1, class_list.size(), CV_32FC1, classes_scores);
          // std::cout<<"Scores size"<<scores;
          // Perform minMaxLoc and acquire index of best class score.
          cv::Point class_id;
          double max_class_score;
          cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
          // Continue if the class score is above the threshold.
          // std::cout<<"Max class scores:"<<max_class_score;
          if (max_class_score > SCORE_THRESHOLD)
          {
              // Store class ID and confidence in the pre-defined respective
              
              std::cout<<"inside max class if";
              confidences.push_back(confidence);
              class_ids.push_back(class_id.x);

              // Center.
              float cx = data[0];
              float cy = data[1];
              // Box dimension.
              float w = data[2];
              float h = data[3];
              // Bounding box coordinates.
              int left = int((cx - 0.5 * w) * x_factor);
              int top = int((cy - 0.5 * h) * y_factor);
              int width = int(w * x_factor);
              int height = int(h * y_factor);
              // Store good detections in the boxes vector.
              boxes.push_back(cv::Rect(left, top, width, height));
          }

      }
      // Jump to the next column.
      data += 85;
  }

  // Perform Non Maximum Suppression and draw predictions.
  std::vector<int> indices;
  cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, indices); 
  // std::cout<<"Indices :"<<indices.size();
  // std::cout<<"No.of humans:"<<boxes.size();
  for (int i = 0; i < indices.size(); i++)
  {
      int idx = indices[i];
      cv::Rect box = boxes[idx];

      int left = box.x;
      int top = box.y;
      int width = box.width;
      int height = box.height;
      // Draw bounding box.
      cv::rectangle(input_image, cv::Point(left, top), cv::Point(left + width,
      top + height), BLUE, 3*THICKNESS);

      // Get the label for the class name and its confidence.
      std::string label = cv::format("%.2f", confidences[idx]);
      label = class_list[class_ids[idx]] + ":" + label;
      int baseLine;
      cv::Size label_size = cv::getTextSize(label, FONT_FACE, FONT_SCALE,
      THICKNESS, &baseLine);
      top = std::max(top, label_size.height);
  // Top left corner.
      cv::Point tlc = cv::Point(left, top);
  // Bottom right corner.
      cv::Point brc = cv::Point(left + label_size.width, top +
      label_size.height + baseLine);
  // Draw black rectangle.
      cv::rectangle(input_image, tlc, brc, BLACK, cv::FILLED);
  // Put the label on the black rectangle.
      cv::putText(input_image, label, cv::Point(left, top +
      label_size.height), FONT_FACE, FONT_SCALE, YELLOW, THICKNESS);
  
  // cv::Mat m1 = cv::Mat::zeros(1, 1, CV_64F);
  // return m1;
  
    // perception::Visualization::displayResults();
    // perception::Visualization::createBoundingBox(input_image,label,left,top,FONT_FACE, FONT_SCALE, THICKNESS,YELLOW, BLACK);
  }
  //  perception::Visualization::displayResults();
   cv::imshow("POSTPROCESS", input_image);
   cv::waitKey(0);
   return input_image;
    }