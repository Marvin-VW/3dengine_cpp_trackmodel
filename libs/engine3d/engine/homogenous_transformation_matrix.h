// Copyright (C) 2024 twyleg
#pragma once

#include "parameter.h"

#include <opencv2/opencv.hpp>

namespace parameter = engine3d::engine::parameter;

namespace engine3d::engine::homogeneous_transformation_matrix {

class Matrix: public cv::Mat{

public:

	Matrix(const parameter::MatrixParameter&);
	Matrix(cv::MatExpr);

	parameter::MatrixParameter mParameter;
};


class Point3d: public cv::Mat {

public:

	Point3d();
	Point3d(double x, double y, double z);
	Point3d(cv::MatExpr);

	double getX() const { return at<double>(0); }
	double getY() const { return at<double>(1); }
	double getZ() const { return at<double>(2); }
};

}
