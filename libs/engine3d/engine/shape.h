// Copyright (C) 2024 Marvin-VW
#pragma once
#include <opencv2/opencv.hpp>

#include <vector>

struct triangle
{
	cv::Mat point[3];
    cv::Mat camera_points[3];
    cv::Mat world_points[3];
    cv::Mat normal;
    cv::Mat centroid;
    double ilm;
    cv::Scalar color;
};


struct mesh
{
	std::vector<triangle> tris;
};

class Shape {

public:

	cv::Mat createPoint(double x, double y, double z);
    std::vector<triangle> generate_mesh(double x, double y, double z);
    void set_position(double x, double y, double z, triangle* mesh);

};