// Copyright (C) 2024 Daniel-VW
#pragma once

#include "engine3d/engine/triangle.h"

#include <vector>
#include <opencv2/opencv.hpp>

namespace engine3d::straight_calculator {

class Straight {

public:

    cv::Mat createPoint(double x, double y, double z);
    std::vector<triangle> generate_straight(
        double track_length,
        double track_width_left,
        double track_width_right,
        double stripeNumber,
        double stripeLength,
        double line_width,
        bool left_line,
        bool dashed_line,
        bool right_line
    );

};

}