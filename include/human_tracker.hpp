/**
 * @file human_tracker.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This File contains the implementation of tracker algorithm with bounding box coordinates.
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __HUMAN_TRACKER_H__
#define __HUMAN_TRACKER_H__
#pragma once

#include <iostream>

namespace perception 
{
    class HumanTracker
    {
        // *cv2.Tracker tracker;
        bool isInitialized;

        public:
        void Initialize();

        void update();
    };
}

#endif
