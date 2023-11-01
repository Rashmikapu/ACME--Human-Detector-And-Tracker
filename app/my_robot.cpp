/**
 * @file my_robot.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The file contains the implementation of MyRobot class
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <../include/my_macros.hpp>
#include <../include/my_robot.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>
#include <iostream>

perception::MyRobot::MyRobot() {
  // Sample intrinsic matrix K
  K = (cv::Mat_<double>(3, 3) << 600.0, 0, 320.0, 0, 600.0, 240.0, 0, 0, 1.0);

  // Sample rotation matrix R (identity matrix, no rotation)
  R = cv::Mat::eye(3, 3, CV_64F);

  // Sample translation vector T
  T = (cv::Mat_<double>(3, 1) << 0, 0,
       2.0); // Assuming a translation of 2 units along the Z-axis
}

perception::MyRobot::MyRobot(cv::Mat my_K, cv::Mat my_R, cv::Mat my_T)
    : K(my_K), R(my_R), T(my_T) {}

void perception::MyRobot::run() {
  std::vector<cv::Mat> detections;
  cv::Mat detector;
  std::string model_path = "data/models/yolov5s.onnx";
  net = yolo.YoloModel(model_path);
  cv::VideoCapture cap(0);

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

    detector = yolo.postProcess(frame, detections, &class_ids, &confidences,
                                &boxes, &indices);

    std::vector<cv::Rect2d> bboxes;
    perception::Visualization::createBoundingBox(indices, boxes, &bboxes, frame,
                                                 yolo.class_list, class_ids,
                                                 confidences);

    perception::HumanTracker tracker_object;
    tracker_object.Initialize();
    tracker_object.update(bboxes, detector);
    perception::Visualization::displayResults(net, detector);

    // Transform and print the bounding box coordinates in Robot reference frame
    double X, Y, Z;
    TransformToRobotFrame(boxes, &X, &Y, &Z);
    std::cout << X << "," << Y << "," << Z << std::endl;

    if (cv::waitKey(25) == 27) // ESC key to exit
      break;
  }
  cap.release();

  // Close the OpenCV window
  cv::destroyAllWindows();
}

void perception::MyRobot::RunOnImage() {
  std::string model_path = "data/models/yolov5s.onnx";
  net = yolo.YoloModel(model_path);

  cv::Mat frame = cv::imread("data/sample.jpeg");

  if (frame.empty()) {
    std::cerr << "Could not read the image." << std::endl;
  }

  cv::Mat new_frame = frame.clone();
  std::vector<cv::Mat> detections;
  cv::Mat detector;
  detections = yolo.preProcess(frame, net);
  std::vector<int> class_ids;
  std::vector<float> confidences;
  std::vector<cv::Rect> boxes;
  std::vector<int> indices;

  detector = yolo.postProcess(frame, detections, &class_ids, &confidences,
                              &boxes, &indices);

  std::vector<cv::Rect2d> bboxes;
  perception::Visualization::createBoundingBox(
      indices, boxes, &bboxes, frame, yolo.class_list, class_ids, confidences);

  perception::HumanTracker tracker_object;
  tracker_object.Initialize();
  tracker_object.update(bboxes, detector);

  perception::Visualization::displayResults(net, detector);

  // Transform and print the bounding box coordinates in Robot reference frame
  double X, Y, Z;
  TransformToRobotFrame(boxes, &X, &Y, &Z);
  std::cout << X << "," << Y << "," << Z << std::endl;
  cv::waitKey(0);
}

void perception::MyRobot::TransformToRobotFrame(
    std::vector<cv::Rect> &detected_objects, double *X, double *Y, double *Z) {
  // Loop through each detected object
  for (const cv::Rect &bbox : detected_objects) {
    // Calculate the center of the bounding box
    cv::Point2f center(bbox.x + bbox.width / 2.0, bbox.y + bbox.height / 2.0);

    // Create a 3D point in normalized camera coordinates
    cv::Mat normalized_point = (cv::Mat_<double>(3, 1) << center.x, center.y,
                                1.0); // Assuming normalized coordinates

    // Convert from normalized camera coordinates to camera frame
    cv::Mat camera_frame_point = R * normalized_point + T;

    // Extract the X, Y, Z coordinates in the camera frame or robot frame
    if (X)
      *X = camera_frame_point.at<double>(0, 0);
    if (Y)
      *Y = camera_frame_point.at<double>(1, 0);
    if (Z)
      *Z = camera_frame_point.at<double>(2, 0);
  }
}