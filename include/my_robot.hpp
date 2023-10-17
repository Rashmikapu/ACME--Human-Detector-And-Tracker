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