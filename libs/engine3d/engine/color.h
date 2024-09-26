// Copyright (C) 2024 Marvin-VW

#include <opencv2/opencv.hpp>

#include <vector>
#include <tuple>
#include <algorithm>
#include <random>
#include <cmath>

class Color {
public:

    double intensity(cv::Vec3f light_direction, cv::Mat& normal);
    cv::Scalar bgr_to_hsl(const cv::Scalar& bgr);
    cv::Scalar hsl_to_bgr(const cv::Scalar& hls);
    cv::Scalar adjust_bgr_intensity(cv::Scalar& base_color, double intensity) ;

};
