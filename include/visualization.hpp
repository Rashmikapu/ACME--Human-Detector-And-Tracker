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
  static void displayResults();

   /**
   * @brief Create Bounding box
   * 
   */
  static void createBoundingBox();
};
}  // namespace perception

#endif
