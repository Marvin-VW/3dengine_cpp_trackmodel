// Copyright (C) 2024 Marvin-VW
#pragma once

namespace engine3d::straight_calculator::parameter {

struct StraightParameter {
    double length;
    double width;
    double wantedStripeNum;
    double stripeLength;
    double lineDistance;
    bool leftLine;
    bool stripedLine;
    bool rightLine;   
};

}