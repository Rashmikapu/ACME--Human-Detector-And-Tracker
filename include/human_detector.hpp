/**
 * @file human_detector.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This file contains the import of YOLO model and detecting humans.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HUMAN_DETECTOR_H__
#define __HUMAN_DETECTOR_H__
#pragma once
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// using namespace cv;
// using namespace std;
// using namespace cv::dnn;
namespace perception {
class HumanDetector {
  // net my_net;
  float input_height;
  float input_width;
  cv::dnn::Net net;
  std::vector<std::string> class_list;
  const float SCORE_THRESHOLD = 0.5;
  const float NMS_THRESHOLD = 0.45;
  const float CONFIDENCE_THRESHOLD = 0.45;
  const float FONT_SCALE = 0.7;
  const int FONT_FACE = cv::FONT_HERSHEY_SIMPLEX;
  const int THICKNESS = 1;
  cv::Scalar BLACK = cv::Scalar(0, 0, 0);
  cv::Scalar BLUE = cv::Scalar(255, 178, 50);
  cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
  cv::Scalar RED = cv::Scalar(0, 0, 255);
  // cv::Mat frame;

 public:
  HumanDetector();
  cv::dnn::Net YoloModel();

  std::vector<cv::Mat> preProcess(cv::Mat &input, cv::dnn::Net &model);

  cv::Mat postProcess(cv::Mat &input, std::vector<cv::Mat> &detections);
};
}  // namespace perception

#endif