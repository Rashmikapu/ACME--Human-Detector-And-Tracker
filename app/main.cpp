/**
 * @file main.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The file contains the initialization of the robot.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <fstream>
#include "../include/human_detector.hpp"
#include <../include/my_robot.hpp>
// #include "../include/my_robot.hpp"

#include <opencv2/opencv.hpp>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// using namespace cv;
// using namespace std;
// using namespace cv::dnn;

int main() {
  perception::MyRobot my_robot;
  cv::Mat input_image = cv::Mat::zeros(1, 1, CV_64F);
  cv::Mat frame = cv::imread(
      "/home/rashmikapu/Desktop/808x/midterm/Human-Detector-And-Tracker/app/sample.jpeg");
  std::vector<cv::Mat> detections(10, cv::Mat());
  my_robot.run();
  return 0;
}
