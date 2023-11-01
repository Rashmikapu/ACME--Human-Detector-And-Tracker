/**
 * @file visualization.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to visualize each frame of the video detecting
 * and tracking humans
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __VISUALIZATION_H__
#define __VISUALIZATION_H__
#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

namespace perception {
/**
 * @class Visualization
 * @brief A utility class for displaying results and creating bounding boxes for
 * visualization.
 */
class Visualization {
public:
  /**
   * @brief Display the detection results
   *
   * @param net The neural network model used for detection.
   * @param detector The input image containing detection results.
   *
   */
  static void displayResults(cv::dnn::Net &net, cv::Mat &detector);

  /**
   * @brief Create bounding boxes for detected objects.
   *
   * @param indices A vector of indices of valid detections.
   * @param boxes A vector of bounding boxes for detected objects.
   * @param bboxes A vector to store bounding boxes (Rect2d format).
   * @param input_image The input image for which bounding boxes are created.
   * @param class_list A list of class labels for detected objects.
   * @param class_ids A vector of class IDs for detected objects.
   * @param confidences A vector of detection confidences.
   *
   * This method creates bounding boxes for detected objects based on the
   * provided indices, boxes, and additional information. The resulting bounding
   * boxes are stored in the bboxes vector.
   */
  static void createBoundingBox(std::vector<int> indices, std::vector<cv::Rect> boxes,
                    std::vector<cv::Rect2d> *bboxes, cv::Mat &input_image,
                    std::vector<std::string> class_list,
                    std::vector<int> class_ids, std::vector<float> confidences);
};
} // namespace perception

#endif
