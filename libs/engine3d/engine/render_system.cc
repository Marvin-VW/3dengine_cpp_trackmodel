// Copyright (C) 2024 Marvin-VW
#include "render_system.h"
#include "camera_model.h"
#include "fps_counter.h"
#include "clipping_space.h"
#include "color.h"
#include "vectors.h"
#include "parameter.h"

#include <iostream>
#include <exception>

namespace HTM = engine3d::engine::homogeneous_transformation_matrix;
namespace parameter = engine3d::engine::parameter;

RenderSystem::RenderSystem(
    CameraModel& cameraModel, 
    Shape& Shape, 
    ClippingSpace& ClippingSpace,
    Vectors& Vectors,
    Color& Color,
    FpsCounter& FpsCounter
    )

    : mCameraModel(cameraModel),
      mShape(Shape),
      mClippingSpace(ClippingSpace),
      mVectors(Vectors),
      mColor(Color),
      mFpsCounter(FpsCounter)
{
}

void RenderSystem::create_matrices(const parameter::Parameter parameter)
{

	// Update homogeneous transformation matrices
	mCameraModel.V_T_C = HTM::Matrix(parameter.vehicle_to_camera_parameter);

/*

        // Original matrices
    double matrixK_data[4 * 4] = {
        -1.83697019872103e-16, -1, 2.298976008042464e-48, 1.194030629168669e-17,
        -1.83697019872103e-16, 3.374459510989179e-32, -1, 0.14,
        1, -1.83697019872103e-16, -1.83697019872103e-16, -0.06499999999999997,
        0, 0, 0, 1
    };

    cv::Mat matrixK(4, 4, CV_64F, matrixK_data);


    mCameraModel.C_T_V = matrixK;

    */

	mCameraModel.C_T_V = mCameraModel.V_T_C.inv();
    std::cout << mCameraModel.C_T_V << std::endl;
	mCameraModel.V_T_Cube = HTM::Matrix(parameter.vehicle_to_cube_parameter);

}

void RenderSystem::update_fps()
{
    mFpsCounter.update();
    std::string fps_text = "FPS: " + std::to_string(static_cast<int>(mFpsCounter.get_fps_filtered()));
    cv::putText(mCameraModel.getCameraImage(), fps_text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

}

cv::Mat RenderSystem::renderFrame() {
    return mCameraModel.getCameraImage();
}
