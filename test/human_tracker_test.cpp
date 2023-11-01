/**
 * @file human_tracker_test.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The test suite is used to test the functionality of human tracker
 * methods
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include <../include/human_tracker.hpp>


#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>


cv::Mat image4 = cv::imread("../../data/sample.jpeg");
int width = image4.cols;
perception::HumanTracker tracker;
std::vector<cv::Rect2d> bboxes2;
/**
 * @brief Construct a new TEST object which will test the updation of tracker
 * update
 *
 */
TEST(Human_Tracker_Test, Initialize_Update) {
  bboxes2.push_back(cv::Rect2d(10, 10, 20, 20));
  bboxes2.push_back(cv::Rect2d(30, 30, 40, 40));

  tracker.Initialize();
  tracker.update(bboxes2, image4);
  EXPECT_EQ(bboxes2.size(), 2);
}
