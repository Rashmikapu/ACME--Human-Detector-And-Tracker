/**
 * @file visualization.hpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief This program is used to visualize each frame of the video detecting and tracking humans
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __VISUALIZATION_H__
#define __VISUALIZATION_H__
#pragma once

#include <iostream>

namespace perception 
{
    class Visualization
    {
        public:

        static void displayResults();
        static void createBoundingBox();
    };
}

#endif