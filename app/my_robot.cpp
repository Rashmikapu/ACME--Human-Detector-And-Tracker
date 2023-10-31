#include <../include/my_robot.hpp>

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <../include/human_detector.hpp>
#include <../include/visualization.hpp>
// using namespace cv;
perception::MyRobot::MyRobot() {}

void perception::MyRobot::run() {
  
  
  cv::Mat frame = cv::imread(
      "/home/rashmikapu/Desktop/808x/midterm/Human-Detector-And-Tracker/app/sample.jpeg");
  if (frame.empty()) {
        std::cerr << "Could not read the image." << std::endl;
  }
  net = yolo.YoloModel();
  // cv::namedWindow("Image", cv::WINDOW_NORMAL);
  // cv::imshow("Image",frame);
  // cv::waitKey(0);
  cv::VideoCapture cap(0); // 0 corresponds to the default camera (you can try different values if you have multiple cameras)

    // Check if the camera was opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not access the camera." << std::endl;
    }

    // Set the frame width and height (adjust as needed)
    while (true) {
        cv::Mat frame;
        // Read a frame from the camera
        cap >> frame;

        // Perform any processing on the frame if needed
        cv::Mat new_frame = frame.clone();
        detections = yolo.preProcess(frame, net);
        perception::Visualization::displayResults();
        // std::cout<<"Worked";
        // std::cout<<"detections:"<<std::endl<<detections[0];
        cv::Mat detector = yolo.postProcess(frame, detections);
        std::vector<double> layersTimes;
        double freq = cv::getTickFrequency() / 1000;
        double t = net.getPerfProfile(layersTimes) / freq;
        std::string label = cv::format("Inference time : %.2f ms", t);
        cv::putText(detector, label, cv::Point(20, 40), yolo.FONT_FACE, yolo.FONT_SCALE, yolo.RED);
        cv::namedWindow("Output", cv::WINDOW_NORMAL);
        cv::imshow("Output", detector);
        // cv::waitKey(0);
        if (cv::waitKey(25) == 27) // ESC key to exit
            break;

        
    }
cap.release();

    // Close the OpenCV window
cv::destroyAllWindows();
}
