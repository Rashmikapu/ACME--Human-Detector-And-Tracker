/**
 * @file human_tracker.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This File contains the implementation of tracker algorithm with
 * bounding box coordinates.
 * @version 0.1
 * @date 2023-10-31
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
  bool isInitialized;
  cv::Ptr<cv::Tracker> csrt_tracker;
 public:
  /**
   * @brief Default constructor for the HumanTracker class.
   *
   * This constructor initializes the HumanTracker object with default values.
   */
  HumanTracker();
  
   /**
   * @brief Creates and configures the tracking algorithm.
   */
  void Initialize();

  /**
   * @brief Update the human tracking with the latest frame.
   *
   * @param bboxes A vector of bounding boxes representing the human targets.
   * @param input_image The latest frame or image for tracking.
   *
   * This method updates the human tracking algorithm with the latest frame and the
   * bounding boxes of the humans to be tracked.
   */
  void update(std::vector<cv::Rect2d> bboxes, cv::Mat& input_image) ;
};
}  // namespace perception

#endif
