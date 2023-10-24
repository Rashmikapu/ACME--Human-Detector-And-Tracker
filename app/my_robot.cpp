#include <../include/my_robot.hpp>

#include <opencv2/opencv.hpp>

#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>
// using namespace cv;
perception::MyRobot::MyRobot() {}

void perception::MyRobot::run() {
  net = yolo.YoloModel();
  cv::Mat frame = cv::imread(
      "/home/rashmikapu/Desktop/808x/midterm/Human-Detector-And-Tracker/app/"
      "sample.jpg");
  cv::Mat new_frame = frame.clone();
  detections = yolo.preProcess(frame, net);
  detector = yolo.postProcess(new_frame, detections);
  tracker.Initialize();
  tracker.update();
  Visualization::displayResults();
  Visualization::createBoundingBox();
  //   std::vector<double> layersTimes;
  // double freq = getTickFrequency() / 1000;
  // double t = net.getPerfProfile(layersTimes) / freq;
  // std::string label = cv::format("Inference time : %.2f ms", t);
  // putText(img, label, Point(20, 40), FONT_FACE, FONT_SCALE, RED);

  cv::imshow("Output", frame);
}
