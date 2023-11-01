/**
 * @file my_macros.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This file contains macros used in the program.
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __MY_MACROS_H__
#define __MY_MACROS_H__
#pragma once

#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

/**
 * @brief Macros definitions
 * 
 */
#define SCORE_THRESHOLD 0.5f
#define NMS_THRESHOLD 0.45f
#define CONFIDENCE_THRESHOLD 0.45f
#define FONT_SCALE 0.7f
#define FONT_FACE cv::FONT_HERSHEY_SIMPLEX
#define THICKNESS 1
#define BLACK cv::Scalar(0, 0, 0)
#define BLUE cv::Scalar(255, 178, 50)
#define YELLOW cv::Scalar(0, 255, 255)
#define RED cv::Scalar(0, 0, 255)


#endif