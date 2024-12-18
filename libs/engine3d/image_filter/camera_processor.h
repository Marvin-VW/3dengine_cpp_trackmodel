#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

namespace engine3d::image_filter {

struct line {
    cv::Point start_point;
    cv::Point end_point;
    int length;
};

struct line_pair {
    line pair_left;
    line pair_right;
};

class CameraProcessor {
public:

    std::vector<line_pair> process_Image(const cv::Mat& frame, std::vector<int> rows);
    cv::Mat getResultFrame() const { return detected_lanes; }

private:
    void setFrame(const cv::Mat& new_frame);
    void maskFrame(std::vector<int> rows);
    void findWhitePixels(std::vector<int> rows);
    void findPixelPairs();

    cv::Mat frame;
    cv::Mat gray_frame;
    cv::Mat masked_frame;
    cv::Mat detected_lanes;
    std::vector<cv::Point> white_pixels;
    std::vector<line> detected_lines;
    std::vector<line_pair> detected_pairs;

    int min_pixel_count_line = 5;
    int max_pixel_count_line = 30;

    int min_pixel_count_track_width = 250;
    int max_pixel_count_track_width = 500;
};

}