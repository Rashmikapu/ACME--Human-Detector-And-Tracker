/**
 * @file human_tracker.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This File contains the implementation of tracker algorithm with
 * bounding box coordinates.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __HUMAN_TRACKER_H__
#define __HUMAN_TRACKER_H__
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <iostream>
#include <vector>

namespace perception {
/**
 * @class HumanTracker
 * @brief Class for tracking humans using computer vision-based tracking algorithms.
 */
class HumanTracker {
  // *cv2.Tracker tracker;
  bool isInitialized;
  cv::Ptr<cv::Tracker> csrt_tracker;
 public:
  /**
   * @brief Constructor for the HumanTracker class.
   */
  HumanTracker();
  
   /**
   * @brief Creates and configures the tracking algorithm.
   */
  void Initialize();

  /**
   * @brief Update the human tracking with the latest frame.
   */
  void update(std::vector<cv::Rect2d> bboxes, cv::Mat& input_image) ;
};
}  // namespace perception

#endif
