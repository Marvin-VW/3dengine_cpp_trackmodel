// Copyright (C) 2024 twyleg
#pragma once

#include <opencv2/opencv.hpp>

namespace engine3d::engine::homogeneous_transformation_matrix {

class Matrix: public cv::Mat{

public:

	struct MatrixParameter {
		double transX;
		double transY;
		double transZ;
		double rotRoll;
		double rotPitch;
		double rotYaw;
	};

	struct UIParameter {
		bool showNormals;
		bool showPoints;
		bool showFaces;
	};

	struct Parameter {

		MatrixParameter vehicle_to_camera_parameter;
		MatrixParameter vehicle_to_cube_parameter;
		UIParameter ui_parameter;

	};

	Matrix(const MatrixParameter&);
	Matrix(cv::MatExpr);

	MatrixParameter mParameter;
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
