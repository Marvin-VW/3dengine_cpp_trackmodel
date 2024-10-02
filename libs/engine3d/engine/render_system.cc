// Copyright (C) 2024 Marvin-VW
#include "render_system.h"
#include "homogenous_transformation_matrix.h"
#include "camera_model.h"
#include "fps_counter.h"
#include "clipping_space.h"
#include "color.h"
#include "vectors.h"

#include <iostream>
#include <exception>

namespace HTM = playground_camera_model::homogeneous_transformation_matrix;

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))

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

void RenderSystem::create_matrices(std::vector<double> trackbarPos)
{

	HTM::Matrix::Parameter vehicle_to_camera_parameter{
		(trackbarPos[0]-10000)/1000.0,
		(trackbarPos[1]-10000)/1000.0,
		(trackbarPos[2]-10000)/1000.0,
		DEG_TO_RAD(trackbarPos[3]/10.0),
		DEG_TO_RAD(trackbarPos[4]/10.0),
		DEG_TO_RAD(trackbarPos[5]/10.0)
	};

	HTM::Matrix::Parameter vehicle_to_cube_parameter{
		(trackbarPos[6]-10000)/1000.0,
		(trackbarPos[7]-10000)/1000.0,
		(trackbarPos[8]-10000)/1000.0,
		DEG_TO_RAD(trackbarPos[9]/10.0),
		DEG_TO_RAD(trackbarPos[10]/10.0),
		DEG_TO_RAD(trackbarPos[11]/10.0)
	};

	// Update homogeneous transformation matrices
	mCameraModel.V_T_C = HTM::Matrix(vehicle_to_camera_parameter);
	mCameraModel.C_T_V = mCameraModel.V_T_C.inv();
	mCameraModel.V_T_Cube = HTM::Matrix(vehicle_to_cube_parameter);

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
