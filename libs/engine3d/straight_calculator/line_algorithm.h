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
    double length,
    double width,
    double wantedStripeNum,
    double stripeLength,
    double lineDistance,
    bool leftLine,
    bool stripedLine,
    bool rightLine
    );

};

}