// Copyright (C) 2024 Marvin-VW
#pragma once

#include "render_system.h"
#include "shape.h"
#include "camera_model.h"
#include "homogenous_transformation_matrix.h"
#include "clipping_space.h"
#include "vectors.h"
#include "color.h"

#include <opencv2/core.hpp>

#include <vector>

namespace engine3d::engine {

class Engine {
public:
    Engine(int frame_width, int frame_height);
    ~Engine();

	cv::Mat run(cv::Mat& frame, std::vector<double> trackbarPos);
    RenderSystem* renderer;
    CameraModel* camera;

private:
    Shape* shape;
    HomogenousTransformationMatrix* matrix;
    ClippingSpace* clipping;
    Vectors* vec;
    Color* color;

    std::vector<triangle> mesh;
    std::vector<triangle> visible_mesh;
    std::vector<triangle> clipped_mesh;

    cv::Mat engine_frame;

    double is_triangle_facing_camera(triangle& tri, cv::Vec3d cam);
};

}