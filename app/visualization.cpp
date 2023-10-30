#include <../include/visualization.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>


void perception::Visualization::createBoundingBox(cv::Mat& input_image, std::string label, const int left,
 const int top,const int FONT_FACE, const float FONT_SCALE, const int THICKNESS, cv::Scalar YELLOW, cv::Scalar BLACK) {
    // Draw class labels.
      // draw_label(input_image, label, left, top);
      int baseLine;
      cv::Size label_size = cv::getTextSize(label, FONT_FACE, FONT_SCALE,
      THICKNESS, &baseLine);
      int top1;
      top1 = std::max(top, label_size.height);
  // Top left corner.
      cv::Point tlc = cv::Point(left, top1);
  // Bottom right corner.
      cv::Point brc = cv::Point(left + label_size.width, top1 +
      label_size.height + baseLine);
  // Draw black rectangle.
      cv::rectangle(input_image, tlc, brc, BLACK, cv::FILLED);
  // Put the label on the black rectangle.
      cv::putText(input_image, label, cv::Point(left, top1 +
      label_size.height), FONT_FACE, FONT_SCALE, YELLOW, THICKNESS);
  
  // cv::Mat m1 = cv::Mat::zeros(1, 1, CV_64F);
  // return m1;
  
  cv::imshow("POSTPROCESS", input_image);
  cv::waitKey(0);
//   return input_image;
}

void perception::Visualization::displayResults() {}
