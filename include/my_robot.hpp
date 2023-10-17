/**
 * @file my_robot.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to start the camera or load the video and do all processing for the robot.
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __MY_ROBOT_H__
#define __MY_ROBOT_H__
#pragma once

#include <iostream>
#include "human_detector.hpp"
#include "human_tracker.hpp"

namespace perception 
{
    class MyRobot
    {
        HumanDetector yolo;
        HumanTracker tracker;

        public:
        void run();
    };
}

#endif