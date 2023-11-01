/**
 * @file human_detector.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This file contains the implementation of HumanDetector class
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <../include/human_detector.hpp>
#include <fstream>
#include <opencv2/core/check.hpp>
#include <opencv2/core/cvstd_wrapper.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <../include/my_macros.hpp>
#include <../include/my_robot.hpp>
#include <../include/visualization.hpp>



perception::HumanDetector::HumanDetector() {
  input_height = 640.0;
  input_width = 640.0;
}

cv::dnn::Net perception::HumanDetector::YoloModel(std::string &model_path) {
  class_list.push_back("person");
  net = cv::dnn::readNet(model_path);
  return net;
}

std::vector<cv::Mat> perception::HumanDetector::preProcess(
    cv::Mat &input, cv::dnn::Net &model) {
  // Create a matrix called blob
  cv::Mat blob;

  // Size is to represent the desired image blob size
  // Scalar() is for mean subtraction
  // true : This indicates that the input image should be considered in BGR
  // (Blue, Green, Red) order. false : This parameter specifies whether the
  // input image data should be swapped. If set to true, the Red and Blue
  // channels will be swapped
  cv::dnn::blobFromImage(input, blob, 1.0 / 255.0,
                         cv::Size(input_width, input_height), cv::Scalar(),
                         true, false);

  model.setInput(blob);
  std::vector<cv::Mat> outputs;

  model.forward(outputs, model.getUnconnectedOutLayersNames());

  return outputs;
}

cv::Mat perception::HumanDetector::postProcess(const cv::Mat &input_image,
                                               const std::vector<cv::Mat>
                                               &detections,
                                               std::vector<int> *class_ids,
                                               std::vector<float> *confidences,
                                               std::vector<cv::Rect> *boxes,
                                               std::vector<int> *indices) {
  float x_factor = input_image.cols / input_width;
  float y_factor = input_image.rows / input_height;

  float* data = reinterpret_cast<float*>(detections[0].data);
  // const int dimensions; // = 85;
  const int rows = 25200;

  // Iterate through 25200 detections.
  for (int i = 0; i < rows; ++i) {
    float confidence = data[4];
    // Discard bad detections and continue.
    if (confidence >= CONFIDENCE_THRESHOLD) {
      float *classes_scores = data + 5;

      // Create a 1x85 Mat and store class scores of 80 classes.
      cv::Mat scores(1, class_list.size(), CV_32FC1, classes_scores);

      // Perform minMaxLoc and acquire index of best class score.
      cv::Point class_id;
      double max_class_score;
      cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
      // Continue if the class score is above the threshold.
      if (max_class_score > SCORE_THRESHOLD) {
        // Store class ID and confidence in the pre-defined respective
        confidences->push_back(confidence);
        class_ids->push_back(class_id.x);

        // Center.
        float cx = data[0];
        float cy = data[1];
        // Box dimension.
        float w = data[2];
        float h = data[3];
        // Bounding box coordinates.
        int left = static_cast<int>((cx - 0.5 * w) * x_factor);
        int top = static_cast<int>((cy - 0.5 * h) * y_factor);
        int width = static_cast<int>(w * x_factor);
        int height = static_cast<int>(h * y_factor);
        // Store good detections in the boxes vector.
        boxes->push_back(cv::Rect(left, top, width, height));
      }
    }
    // Jump to the next column.
    data += 85;
  }

  // Perform Non Maximum Suppression and draw predictions.
  cv::dnn::NMSBoxes(*boxes, *confidences, SCORE_THRESHOLD, NMS_THRESHOLD,
                    *indices);

  // cv::Ptr<cv::Tracker> csrt_tracker = cv::TrackerCSRT::create();

  return input_image;
}
