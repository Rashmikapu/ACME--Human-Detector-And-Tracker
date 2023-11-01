/**
 * @file main.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The file contains the main function. It creates the object of my_robot
 * class and calls run function.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <iostream>
#include <../include/my_robot.hpp>
#include <opencv2/opencv.hpp>

#include "../include/human_detector.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main() {
  perception::MyRobot my_robot;
  my_robot.run();
  my_robot.RunOnImage();
  return 0;
}

