// Copyright (C) 2024 Marvin-VW
#pragma once

namespace engine3d::straight_calculator::parameter {

struct StraightParameter {
    double track_length;
    double track_width_left;
    double track_width_right;
    double stripeNumber;
    double stripeLength;
    double line_width;
    bool left_line;
    bool dashed_line;
    bool right_line;
};

}