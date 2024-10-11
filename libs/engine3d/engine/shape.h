// Copyright (C) 2024 Marvin-VW
#pragma once

#include "triangle.h"


#include <opencv2/opencv.hpp>
#include <vector>


class Shape {

public:

	cv::Mat createPoint(double x, double y, double z);
    std::vector<triangle> generate_mesh(double x, double y, double z);
    void set_position(double x, double y, double z, triangle* mesh);

};