#include <gtest/gtest.h>

#include <../include/human_detector.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>


  cv::Mat image = cv::imread(
      "/home/rashmikapu/Desktop/808x/midterm/Human-Detector-And-Tracker/app/sample.jpeg");

// TEST(dummy_test, this_should_pass) {
//   EXPECT_EQ(1, 1);
// }

// TEST(dummy_test, this_should_pass_too) {
//   EXPECT_EQ(my_function1(3), 3);
// }

// TEST(dummy_test, this_will_no_longer_fail) {
//   EXPECT_FLOAT_EQ(my_function2(3.2), 3.2);
// }

perception::HumanDetector my_detector;
cv::dnn::Net net = my_detector.YoloModel();
std::vector<cv::Mat> det = my_detector.preProcess(image, net);
// TEST(modeltest, this_is_to_test_yoloModel_function) { EXPECT_FALSE(net.empty()); }
// // Use cv::Mat::operator== to check if the two Mats are equal.
// TEST(preprocess_test, this_is_to_test_preprocessing) { EXPECT_FALSE(my_detector.preProcess(image, net).empty()); }

// // cv::Mat detector = my_detector.postProcess(image, det);
// TEST(postprocess_test, this_is_to_test_postprocessing) {
//   EXPECT_EQ(my_detector.postProcess(image, det).type(), image.type());
// }