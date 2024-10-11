// Copyright (C) 2024 twyleg
#include "image_processing.h"
#include "engine3d/curve_calculator/arc_algorithm.h"

#include <engine3d/engine/engine.h>

#include <opencv2/opencv.hpp>
#include <fmt/core.h>

#include <optional>

namespace HTM = engine3d::engine::homogeneous_transformation_matrix;

namespace engine3d::core {

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))

ImageProcessing::ImageProcessing(

	engine3d::ui::ImageModel& imageModel,
	engine3d::ui::ParameterModel& parameterModel,
		QObject* parent) :
	QThread(parent),
	mImageModel(imageModel),
	mParameterModel(parameterModel)
{}

ImageProcessing::~ImageProcessing() {}

void ImageProcessing::run() {

	int frame_width = 640*4;
	int frame_height = 480*4;

	cv::Mat camera_frame;
    cv::Mat engine_frame;

	engine3d::engine::Engine engine(frame_width, frame_height);

	engine3d::curve_calculator::Curve curve;

    bool running = true;

    while(running) {

		camera_frame = cv::Mat(frame_height, frame_width, CV_8UC3, cv::Scalar(255,255,255));

		curve.generate_curve(camera_frame, 0, 0, 20, 5, 3.5, 2.0, 0, 90, false, 10);
		std::vector<triangle> mesh = curve.get_curve_mesh();

		engine_frame = engine.run(camera_frame, mesh, getParameters());

		QImage img((uchar*)engine_frame.data, engine_frame.cols, engine_frame.rows, QImage::Format_RGB888);
		mImageModel.setImage(QPixmap::fromImage(img));

		msleep(1000 / 60.0);

    }

}

 HTM::Matrix::Parameter ImageProcessing::getParameters() {

    HTM::Matrix::Parameter parameter;

	parameter.vehicle_to_camera_parameter = {
		(mParameterModel.getCameraSystemTranslationX()-10000)/1000.0,
		(mParameterModel.getCameraSystemTranslationY()-10000)/1000.0,
		(mParameterModel.getCameraSystemTranslationZ()-10000)/1000.0,
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationRoll()/10.0),
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationPitch()/10.0),
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationYaw()/10.0)
	};
 
	parameter.vehicle_to_cube_parameter = {
		(mParameterModel.getCubeSystemTranslationX()-10000)/1000.0,
		(mParameterModel.getCubeSystemTranslationY()-10000)/1000.0,
		(mParameterModel.getCubeSystemTranslationZ()-10000)/1000.0,
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationRoll()/10.0),
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationPitch()/10.0),
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationYaw()/10.0)
	};

    parameter.ui_parameter = {
		static_cast<bool>(mParameterModel.getCubeSystemNormals()),
		static_cast<bool>(mParameterModel.getCubeSystemPoints()),
		static_cast<bool>(mParameterModel.getCubeSystemFaces())
    };

    return parameter;
}

}
