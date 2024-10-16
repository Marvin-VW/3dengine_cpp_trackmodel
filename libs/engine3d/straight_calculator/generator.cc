// Copyright (C) 2024 Marvin-VW
#include "parameter.h"	
#include "line_algorithm.h"

engine3d::straight_calculator::Straight straight;

namespace straight_parameter = engine3d::straight_calculator::parameter;

std::vector<triangle> generateStraightTrack(straight_parameter::StraightParameter straight_parameter) {
    
    std::vector<triangle> mesh;

    mesh = straight.generate_straight(
        straight_parameter.length,
        straight_parameter.width,
        straight_parameter.wantedStripeNum,
        straight_parameter.stripeLength,
        straight_parameter.lineDistance,
        straight_parameter.leftLine,
        straight_parameter.stripedLine,
        straight_parameter.rightLine
    );

    return mesh;

}