/**
 * @file my_robot.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to start the camera or load the video and do all
 * processing for the robot.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __MY_ROBOT_H__
#define __MY_ROBOT_H__
#include <opencv2/dnn/dnn.hpp>
#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "human_detector.hpp"
#include "human_tracker.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// using namespace cv;

namespace perception {
/**
 * @class MyRobot
 * @brief Class representing a robot with the capability to perform human detection and tracking.
 */
class MyRobot {
  HumanDetector yolo;
  cv::dnn::Net net;
  HumanTracker tracker;
  std::vector<cv::Mat> detections;
  std::vector<cv::Mat> detector;

 public:
  /**
   * @brief Constructor for the MyRobot class.
   */
  MyRobot();

  /**
   * @brief Run the robot's operations, including human detection and tracking.
   */
  void run();
};
}  // namespace perception

#endif