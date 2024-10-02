// Copyright (C) 2024 Marvin-VW
#include "render_system.h"
#include "camera_model.h"
#include "fps_counter.h"
#include "clipping_space.h"
#include "color.h"
#include "vectors.h"

#include <iostream>
#include <exception>

namespace HTM = engine3d::engine::homogeneous_transformation_matrix;;

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

void RenderSystem::create_matrices(const HTM::Matrix::Parameter parameter)
{

	// Update homogeneous transformation matrices
	mCameraModel.V_T_C = HTM::Matrix(parameter.vehicle_to_camera_parameter);
	mCameraModel.C_T_V = mCameraModel.V_T_C.inv();
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
