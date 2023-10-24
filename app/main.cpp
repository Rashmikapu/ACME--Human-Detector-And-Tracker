
/**
 * @file main.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The file contains the initialization of the robot.
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include "../include/human_detector.hpp"
#include "my_robot.hpp"
// #include "../include/my_robot.hpp"
#include <opencv2/opencv.hpp>
#include <fstream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
// using namespace cv;
// using namespace std;
// using namespace cv::dnn;

int main() {

  cv::Mat frame = cv::imread("sample.jpeg");//.jpeg");
  perception::MyRobot my_robot;
  my_robot.run();
  return 0;
}
