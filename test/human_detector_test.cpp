/**
 * @file human_detector_test.cpp
 * @author Neha Nitin Madhekar, Rashmi Kapu, Vinay Krishna Bukka
 * @brief The test suite is used to test the functionality of human detector
 * object
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <gtest/gtest.h>

#include <iostream>
#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>

#include <opencv2/opencv.hpp>


std::vector<cv::Rect> boxes;
std::vector<int> indices;
std::vector<int> class_ids;
std::vector<float> confidences;
std::vector<std::string> class_list;
std::vector<cv::Rect2d> bboxes;
cv::Mat image2 = cv::imread("../../data/sample.jpeg");

/**
 * @brief 3 tests are implemented to test
 the functions in Human_detector class, which
 are preprocess, postprocess and yolomodel
 * 
 */
perception::HumanDetector my_detector;

TEST(modeltest, this_is_to_test_yoloModel_function) {
  std::string model_path = "../../data/models/yolov5s.onnx";
  cv::dnn::Net net = my_detector.YoloModel(model_path);
  EXPECT_FALSE(net.empty());
}
// Use cv::Mat::operator== to check if the two Mats are equal.
TEST(preprocess_test, this_is_to_test_preprocessing) {
  std::string model_path = "../../data/models/yolov5s.onnx";
  cv::dnn::Net net = my_detector.YoloModel(model_path);
  EXPECT_FALSE(my_detector.preProcess(image2, net).empty());
}

// cv::Mat detector = my_detector.postProcess(image, det);
TEST(postprocess_test, this_is_to_test_postprocessing) {
  std::string model_path = "../../data/models/yolov5s.onnx";
  cv::dnn::Net net = my_detector.YoloModel(model_path);
  std::vector<cv::Mat> det = my_detector.preProcess(image2, net);
  EXPECT_EQ(
      my_detector
          .postProcess(image2, det, &class_ids, &confidences, &boxes, &indices)
          .type(),
      image2.type());
}
