/**
 * @file my_robot.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to start the camera or load the video and do all
 * processing for the robot.
 * @version 0.1
 * @date 2023-10-31
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


namespace perception {
/**
 * @class MyRobot
 * @brief Class representing a robot with the capability to perform human detection and tracking.
 */
class MyRobot {
  HumanDetector yolo;
  cv::dnn::Net net;
  HumanTracker tracker;

  cv::Mat K;
  cv::Mat R;
  cv::Mat T;

 public:
  /**
   * @brief Default constructor for the MyRobot class.
   *
   * This constructor initializes the MyRobot object with default values.
   */
  MyRobot();

  /**
   * @brief Constructor for the MyRobot class with calibration parameters.
   *
   * @param my_K The camera calibration matrix.
   * @param my_R The rotation matrix.
   * @param my_T The translation matrix.
   */
  MyRobot(cv::Mat my_K, cv::Mat my_R, cv::Mat my_T);

  /**
   * @brief Run the robot's operations, including human detection and tracking on live feed
   */
  void run();

  /**
   * @brief Run the robot's operations, including human detection and tracking on the sample image
   */
  void RunOnImage();

  /**
   * @brief Transform detected objects to the robot's frame of reference.
   *
   * @param detected_objects A vector of rectangles representing detected objects.
   * @param X Output for transformed X-coordinate.
   * @param Y Output for transformed Y-coordinate.
   * @param Z Output for transformed Z-coordinate.
   *
   * This method transforms the coordinates of detected objects from their original
   * frame of reference to the robot's frame of reference. The results are stored in
   * the provided X, Y, and Z values.
   */
  void TransformToRobotFrame(std::vector<cv::Rect> &detected_objects,double* X, double* Y, double*Z);
};
}  // namespace perception

#endif