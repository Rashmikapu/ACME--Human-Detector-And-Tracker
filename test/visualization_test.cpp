/**
 * @file visualization_test.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The test suite is used to test the functionality of visualization
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <gtest/gtest.h>
#include <iostream>
#include <opencv2/opencv.hpp>          // External library headers
#include <../include/visualization.hpp>
std::vector<cv::Rect> boxes1;
std::vector<int> indices1;
std::vector<int> class_ids1;
std::vector<float> confidences1;
std::vector<std::string> class_list1;
std::vector<cv::Rect2d> bboxes1;
cv::Mat image3 = cv::imread("../../data/sample.jpeg");
/**
 * @brief Construct a new TEST object, This object test the bounding box update
 * creation
 *
 */
TEST(VisualizationTest, CreateBoundingBoxTest) {
  // Prepare input data
  indices1.push_back(0);
  boxes1.push_back(cv::Rect(10, 20, 30, 40));
  class_list1.push_back("ClassA");
  class_ids1.push_back(0);
  confidences1.push_back(0.95);
  // Call the function
  perception::Visualization::createBoundingBox(indices1, boxes1, &bboxes1,
                                               image3, class_list1, class_ids1,
                                               confidences1);
  // we can check if bboxes vector contains the
  // expected Rect2d values
  // and if the image was modified as expected
  ASSERT_EQ(bboxes1.size(), 1);
  ASSERT_EQ(bboxes1[0], cv::Rect2d(10, 20, 30, 40));
}
