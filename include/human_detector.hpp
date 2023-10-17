/**
 * @file human_detector.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This file contains the import of YOLO model and detecting humans.
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HUMAN_DETECTOR_H__
#define __HUMAN_DETECTOR_H__
#pragma once

#include <iostream>

namespace perception 
{
    class HumanDetector
    {
        // net my_net;
        int input_height;
        int input_width;

        public:
        void YoloModel();

        void preProcess();

        void postProcess();
    };
}


#endif