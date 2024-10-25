// Copyright (C) 2024 Marvin-VW
#include "parameter.h"	
#include "line_algorithm.h"

engine3d::straight_calculator::Straight straight;

namespace straight_parameter = engine3d::straight_calculator::parameter;

std::vector<triangle> generateStraightTrack(straight_parameter::StraightParameter straight_parameter) {
    
    std::vector<triangle> mesh;

    mesh = straight.generate_straight(
        straight_parameter.track_length,
        straight_parameter.track_width_left,
        straight_parameter.track_width_right,
        straight_parameter.stripeNumber,
        straight_parameter.stripeLength,
        straight_parameter.line_width,
        straight_parameter.left_line,
        straight_parameter.dashed_line,
        straight_parameter.right_line
    );

    return mesh;

}