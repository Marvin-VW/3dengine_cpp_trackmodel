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

class Engine {
public:
    Engine(int frame_width, int frame_height, engine3d::ui::ParameterModel& parameterModel);
    ~Engine();

	cv::Mat run(cv::Mat& frame);
    RenderSystem* renderer;
    CameraModel* camera;

	engine3d::ui::ParameterModel& mParameterModel;

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

    float is_triangle_facing_camera(triangle& tri, cv::Vec3f cam);
};
