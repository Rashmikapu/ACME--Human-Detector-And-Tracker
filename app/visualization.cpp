#include <../include/visualization.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>


void perception::Visualization::createBoundingBox(std::vector<int> indices,std::vector<cv::Rect> boxes, std::vector<cv::Rect2d> bboxes, cv::Mat& input_image,
const int FONT_FACE, const float FONT_SCALE, const int THICKNESS, cv::Scalar YELLOW, cv::Scalar BLACK, cv::Scalar BLUE, std::vector<std::string> class_list,
std::vector<int> class_ids, std::vector<float> confidences) {
    int id=0;
    for (int i = 0; i < indices.size(); i++)
  {
      int idx = indices[i];
      cv::Rect box = boxes[idx];

      int left = box.x;
      int top = box.y;
      int width = box.width;
      int height = box.height;

      bboxes.push_back(cv::Rect2d(left,top,width,height));
      // Draw bounding box.
      cv::rectangle(input_image, cv::Point(left, top), cv::Point(left + width,
      top + height), BLUE, 3*THICKNESS);

      // Get the label for the class name and its confidence.
      std::string label = cv::format("%.2f", confidences[idx]);
     
      label = class_list[class_ids[idx]] + ":" + std::to_string(++id);
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
}
}

void perception::Visualization::displayResults() {}
