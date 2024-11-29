// Copyright (C) 2024 Daniel-VW, Marvin-VW
#include <iostream>
#include <vector>
#include "line_algorithm.h"
#include "parameter.h"


namespace engine3d::straight_calculator {

cv::Mat Straight::createPoint(double x, double y, double z) {
    cv::Mat point(4,1,CV_64F);
    point.at<double>(0) = y;
    point.at<double>(1) = z;
    point.at<double>(2) = x;
    point.at<double>(3) = 1;
    return point;
}

std::vector<triangle> Straight::generate_straight(
    double track_length,
    double track_width_left,
    double track_width_right,
    double stripeNumber,
    double stripeLength,
    double line_width,
    bool left_line,
    bool dashed_line,
    bool right_line
) {

    std::vector<triangle> mesh;

    if (left_line) {
        cv::Mat SecSolidLine_P0 = createPoint(0,                (track_width_left),                0);  // Bottom right
        cv::Mat SecSolidLine_P1 = createPoint(0,                (track_width_left) + line_width,   0); // Bottom left
        cv::Mat SecSolidLine_P2 = createPoint(track_length,     (track_width_left),                0);  // Top right
        cv::Mat SecSolidLine_P3 = createPoint(track_length,     (track_width_left) + line_width,   0);   // Top left

    // Triangles
    mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P2, SecSolidLine_P3} }); 
    mesh.push_back({ {SecSolidLine_P1, SecSolidLine_P0, SecSolidLine_P3} }); 
    }


    if (!dashed_line) {

        cv::Mat SecSolidLine_P0 = createPoint(0,            0,                0);  // Bottom right
        cv::Mat SecSolidLine_P1 = createPoint(0,            line_width,                 0); // Bottom left
        cv::Mat SecSolidLine_P2 = createPoint(track_length, 0,                0);  // Top right
        cv::Mat SecSolidLine_P3 = createPoint(track_length, line_width,                 0);   // Top left

    // Triangles
    mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P2, SecSolidLine_P3} }); 
    mesh.push_back({ {SecSolidLine_P1, SecSolidLine_P0, SecSolidLine_P3} }); 
    }

    
    return mesh;
    }
}