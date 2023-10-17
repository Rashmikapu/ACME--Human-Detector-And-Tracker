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
        void Initializa();

        void update();
    };
}

#endif