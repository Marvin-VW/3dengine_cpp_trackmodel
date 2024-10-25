
// Copyright (C) 2024 Daniel-VW
#include <iostream>
#include <vector>
#include "line_algorithm.h"
#include "parameter.h"


namespace engine3d::straight_calculator {

cv::Mat Straight::createPoint(double x, double y, double z) {
    cv::Mat point(4,1,CV_64F);
    point.at<double>(0) = x;
    point.at<double>(1) = y;
    point.at<double>(2) = z;
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

    if (rightLine) {
        cv::Mat SolidLine_P0 = createPoint(-track_length / 2,    -((track_width_right + line_width / 2) + line_width),    0);  // Bottom right
        cv::Mat SolidLine_P1 = createPoint(-track_length / 2,    -(track_width_right + line_width / 2),                   0);  // Bottom left
        cv::Mat SolidLine_P2 = createPoint(track_length / 2,     -((track_width_right + line_width / 2) + line_width),    0);  // Top right
        cv::Mat SolidLine_P3 = createPoint(track_length / 2,     -(track_width_right + line_width / 2),                   0);  // Top left

    // Triangles
    mesh.push_back({ {SolidLine_P0, SolidLine_P1, SolidLine_P2} }); 
    mesh.push_back({ {SolidLine_P0, SolidLine_P2, SolidLine_P3} }); 
    }

    if (leftLine) {
        cv::Mat SecSolidLine_P0 = createPoint(-track_length / 2,    (track_width_left + line_width / 2),                0);  // Bottom right
        cv::Mat SecSolidLine_P1 = createPoint(-track_length / 2,    (track_width_left + line_width / 2) + line_width,   0); // Bottom left
        cv::Mat SecSolidLine_P2 = createPoint(track_length / 2,     (track_width_left + line_width / 2),                0);  // Top right
        cv::Mat SecSolidLine_P3 = createPoint(track_length / 2,     (track_width_left + line_width / 2) + line_width,   0);   // Top left

    // Triangles
    mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P1, SecSolidLine_P2} }); 
    mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P2, SecSolidLine_P3} }); 
    }

    if (!dashed_line) {
        cv::Mat SecSolidLine_P0 = createPoint(-length / 2, line_width / 2 + (width_left), 0);  // Top left
        cv::Mat SecSolidLine_P1 = createPoint(-length / 2, -line_width / 2 + (width_left), 0); // Bottom left
        cv::Mat SecSolidLine_P2 = createPoint(length / 2, -line_width / 2 + (width_left), 0);  // Bottom right
        cv::Mat SecSolidLine_P3 = createPoint(length / 2, line_width / 2 + (width_left), 0);   // Top right

        // Triangles
        mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P1, SecSolidLine_P2} }); 
        mesh.push_back({ {SecSolidLine_P0, SecSolidLine_P2, SecSolidLine_P3} }); 
    }

    }

    return mesh;
}