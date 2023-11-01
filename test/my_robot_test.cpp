/**
 * @file my_robot.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The test suite is used to test the functionality of my_robot
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>


#include <../include/my_robot.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

perception::MyRobot transform;
std::vector<cv::Rect> bboxes3;
/**
 * @brief Construct a new TEST object which will test the transform coordinates
 * 
 */
TEST(My_robot_test, Transform) {
bboxes3.push_back(cv::Rect(10, 10, 20, 20));
// bboxes2.push_back(cv::Rect2d(30, 30, 40, 40));

double X=0, Y, Z;
transform.TransformToRobotFrame(bboxes3, &X , &Y, &Z);
EXPECT_FALSE(X==0);
}