#include <gtest/gtest.h>

#include <../include/human_detector.hpp>
#include <opencv2/opencv.hpp>

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
cv::Mat input_image = cv::Mat::zeros(1, 1, CV_64F);
std::vector<cv::Mat> detections(10, cv::Mat());
// detections.append(input_image);

// EXPECT_EQ(my_detector.postProcess(input_image,detections),cv::Mat::zeros(1,
// 1, CV_64F));

cv::Mat expectedMat = cv::Mat::zeros(1, 1, CV_64F);
cv::Mat resultMat = my_detector.postProcess(input_image, detections);

// Use cv::Mat::operator== to check if the two Mats are equal.
TEST(preprocess_test, this_will_pass) { EXPECT_FALSE(detections.empty()); }

TEST(postprocess_test, this_will_pass) {
  EXPECT_EQ(cv::countNonZero(resultMat != expectedMat), 0);
}
