/**
 * @file visualization.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to visualize each frame of the video detecting
 * and tracking humans
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __VISUALIZATION_H__
#define __VISUALIZATION_H__
#pragma once

#include <iostream>
#include<opencv2/opencv.hpp>


namespace perception {
/**
 * @class Visualization
 * @brief A utility class for displaying results and creating bounding boxes for visualization.
 */
class Visualization {
 public:
  /**
   * @brief Display the results
   * 
   */
  static void displayResults(cv::dnn::Net &net,cv::Mat &detector);

   /**
   * @brief Create Bounding box
   * 
   */
  static void createBoundingBox(std::vector<int> indices,std::vector<cv::Rect> boxes, std::vector<cv::Rect2d>* bboxes, cv::Mat& input_image,std::vector<std::string> class_list,
std::vector<int> class_ids, std::vector<float> confidences);
};
}  // namespace perception

#endif
 