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