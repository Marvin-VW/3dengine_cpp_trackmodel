// Copyright (C) 2024 Marvin-VW
#pragma once

#include "engine3d/engine/triangle.h"

#include <opencv2/opencv.hpp>

namespace engine3d::curve_calculator {

class Curve {

public:
    void generate_curve(double positionX, double positionY, double radius, double line_width, double step_distance1, 
        double step_distance2, double angle_start, double angle_end, bool dashed, int subdivisions);
    std::vector<triangle> get_curve_mesh();

private:
    std::vector<cv::Point2d> subdivisionPoints(double center_x, double center_y, 
        double startAngle, double endAngle,  double radius, int subdivisions);
    void buildTriangle(std::vector<cv::Point2d> arcPoints_inner, std::vector<cv::Point2d> arcPoints_outer);
    std::vector<triangle> mesh;
};

}