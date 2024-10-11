// Copyright (C) 2024 Marvin-VW
#pragma once
#include <opencv2/opencv.hpp>

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