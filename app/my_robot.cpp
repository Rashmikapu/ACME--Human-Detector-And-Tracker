#include <../include/my_macros.hpp>
#include <../include/my_robot.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <../include/human_tracker.hpp>
#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>

// using namespace cv;
perception::MyRobot::MyRobot() {}

void perception::MyRobot::run() {

  //   cv::Mat frame = cv::imread(
  //       "sample.jpeg");
  //   if (frame.empty()) {
  //         std::cerr << "Could not read the image." << std::endl;
  //   }
  std::vector<cv::Mat> detections;
  cv::Mat detector;
  std::string model_path = "data/models/yolov5s.onnx";
  net = yolo.YoloModel(model_path);
  // cv::namedWindow("Image", cv::WINDOW_NORMAL);
  // cv::imshow("Image",frame);
  // cv::waitKey(0);
  cv::VideoCapture cap(0); // 0 corresponds to the default camera (you can try
                           // different values if you have multiple cameras)

  // Check if the camera was opened successfully
  if (!cap.isOpened()) {
    std::cerr << "Error: Could not access the camera." << std::endl;
  }

  // Set the frame width and height (adjust as needed)
  while (true) {
    cv::Mat frame;
    // Read a frame from the camera
    cap >> frame;

    // Perform any processing on the frame if needed
    detections = yolo.preProcess(frame, net);
    std::vector<int> class_ids;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;
    std::vector<int> indices;

    cv::Mat detector = yolo.postProcess(frame, detections, &class_ids,
                                        &confidences, &boxes, &indices);

    std::vector<cv::Rect2d> bboxes;
    perception::Visualization::createBoundingBox(indices, boxes, &bboxes, frame,
                                                 yolo.class_list, class_ids,
                                                 confidences);
    perception::HumanTracker tracker_object;
    tracker_object.Initialize();
    tracker_object.update(bboxes,detector);
    perception::Visualization::displayResults(net, detector);

    if (cv::waitKey(25) == 27) // ESC key to exit
      break;
  }
  cap.release();

  // Close the OpenCV window
  cv::destroyAllWindows();
}
