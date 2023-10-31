#include "../include/human_tracker.hpp"
#include<opencv2/tracking.hpp>
#include<iostream>
perception::HumanTracker::HumanTracker() { isInitialized = false; }

void perception::HumanTracker::Initialize() {
    csrt_tracker = cv::TrackerCSRT::create();
}

void perception::HumanTracker::update(std::vector<cv::Rect2d> bboxes, cv::Mat& input_image)  {
      for (cv::Rect2d& current_box : bboxes){
        csrt_tracker->update(input_image, current_box);
        cv::rectangle(input_image, current_box, cv::Scalar(255,0,0), 2);
      }
}
