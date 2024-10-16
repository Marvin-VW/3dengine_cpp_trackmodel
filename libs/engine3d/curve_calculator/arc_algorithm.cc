// Copyright (C) 2024 Marvin-VW
#include "arc_algorithm.h"

#include <cmath>


namespace engine3d::curve_calculator {

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))
#define RAD_TO_DEG(x) ((x) * (180.0 / M_PI))

cv::Mat createPoint(double x, double y, double z){
	cv::Mat point(4,1,CV_64F);
	point.at<double>(0) = x;
	point.at<double>(1) = y;
	point.at<double>(2) = z;
	point.at<double>(3) = 1;
	return point;
}

std::vector<cv::Point2d> Curve::subdivisionPoints(double center_x, double center_y, double startAngle, double endAngle,  double radius, int subdivisions) {
    std::vector<cv::Point2d> arcPoints;
    for (int i = 0; i <= subdivisions; i++) {
        double theta = startAngle + (endAngle - startAngle) * i / subdivisions;
        double x = static_cast<double>(center_x + radius * cos(theta));
        double y = static_cast<double>(center_y + radius * sin(theta));

        std::cout << x << " " << y << std::endl;

        arcPoints.push_back(cv::Point2d(x, y));
    }
    return arcPoints;
}

void Curve::buildTriangle(std::vector<cv::Point2d> arcPoints_inner, std::vector<cv::Point2d> arcPoints_outer) {

    for (size_t i = 0; i < arcPoints_inner.size() - 1; i++) {

        triangle upper_triangle;
        triangle bottom_triangle;

        //upper triangle
        upper_triangle.point[0] = createPoint(arcPoints_outer[i].x, arcPoints_outer[i].y, 1.0);
        upper_triangle.point[1] = createPoint(arcPoints_outer[i+1].x, arcPoints_outer[i+1].y, 1.0);
        upper_triangle.point[2] = createPoint(arcPoints_inner[i].x, arcPoints_inner[i].y, 1.0);

        //bottom triangle
        bottom_triangle.point[0] = createPoint(arcPoints_inner[i].x, arcPoints_inner[i].y, 1.0);
        bottom_triangle.point[1] = createPoint(arcPoints_outer[i+1].x, arcPoints_outer[i+1].y, 1.0);
        bottom_triangle.point[2] = createPoint(arcPoints_inner[i+1].x, arcPoints_inner[i+1].y, 1.0);

        mesh.push_back(upper_triangle);
        mesh.push_back(bottom_triangle);
    }
}

void Curve::generate_curve(double positionX, double positionY, double radius, double line_width, double step_distance1, double step_distance2, double angle_start, double angle_end, bool dashed, int subdivisions) {
    
    mesh.clear();

    double start_radians = DEG_TO_RAD(angle_start);
    double end_radians = DEG_TO_RAD(angle_end);

    int center_x = 0+positionX;
    int center_y = 0+positionY;

    double current_angle = start_radians;
    int step_toggle = 0;

    double prev_angle = end_radians;
    bool first_step = true;

    if (!dashed) {

        std::vector<cv::Point2d> arcPoints_inner;
        std::vector<cv::Point2d> arcPoints_outer;

        arcPoints_inner = subdivisionPoints(center_x, center_y, start_radians, end_radians, radius, subdivisions);
        arcPoints_outer = subdivisionPoints(center_x, center_y, start_radians, end_radians, radius+line_width, subdivisions);

        buildTriangle(arcPoints_inner, arcPoints_outer);
    
    }
    else {
        if (end_radians < current_angle) {
            std::swap(end_radians, current_angle);
        }

        while (current_angle <= end_radians) {
            if (!first_step) {
                double step_distance = (step_toggle % 2 == 0) ? step_distance1 : step_distance2;
                step_toggle++;

                double arc_length = step_distance;
                current_angle += arc_length / radius;
            }

            bool second_step = (step_toggle % 2 != 0);

            if (current_angle > end_radians) {
                current_angle = end_radians;
            }

            std::vector<cv::Point2d> arcPoints_inner;
            std::vector<cv::Point2d> arcPoints_outer;
            arcPoints_inner = subdivisionPoints(center_x, center_y, prev_angle, current_angle, radius, subdivisions);
            arcPoints_outer = subdivisionPoints(center_x, center_y, prev_angle, current_angle, radius+line_width, subdivisions);

            if (second_step && !first_step) {
                
                buildTriangle(arcPoints_inner, arcPoints_outer);

            }

            if (current_angle >= end_radians) {
                break;
            }

            prev_angle = current_angle;
            first_step = false;
        }
    }
}

std::vector<triangle> Curve::get_curve_mesh() {
    return this->mesh;
}

}