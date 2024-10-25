// Copyright (C) 2024 twyleg, Marvin-VW
#include "image_processing.h"
#include "engine3d/curve_calculator/generator.cc"
#include "engine3d/straight_calculator/generator.cc"

#include <engine3d/engine/engine.h>

#include <opencv2/opencv.hpp>
#include <fmt/core.h>

#include <optional>
#include <iostream>

namespace engine_parameter = engine3d::engine::parameter;
namespace curve_parameter = engine3d::curve_calculator::parameter;

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

	std::vector<triangle> mesh;

	engine3d::engine::Engine engine(frame_width, frame_height);

    bool running = true;

    while(running) {

		camera_frame = cv::Mat(frame_height, frame_width, CV_8UC3, cv::Scalar(255,255,255));

		getCurveParameters();
		getEngineParameters();
		getStraightParameters();

		if (mParameterModel.getShowStraight()) {
			mesh = generateStraightTrack(straight_parameter);
		}

		if (mParameterModel.getShowCurve()) {
			mesh = generateTrack(curve_parameter);
		}

		if (!mParameterModel.getShowCurve() && !mParameterModel.getShowStraight()) {
			mesh.clear();
		}

		engine_frame = engine.run(camera_frame, mesh, engine_parameter);

		QImage img((uchar*)engine_frame.data, engine_frame.cols, engine_frame.rows, QImage::Format_RGB888);
		mImageModel.setImage(QPixmap::fromImage(img));

		msleep(1000 / 60.0);
    }

}

void ImageProcessing::getStraightParameters() {

	straight_parameter.track_length = mParameterModel.getStraight_track_length();
	straight_parameter.track_width_left = mParameterModel.getStraight_track_width_left();
	straight_parameter.track_width_right = mParameterModel.getStraight_track_width_right();
	straight_parameter.stripeNumber =  mParameterModel.getStraight_stripeNumber();
	straight_parameter.stripeLength = mParameterModel.getStraight_stripeLength();
	straight_parameter.line_width = mParameterModel.getStraight_line_width();
	straight_parameter.left_line = mParameterModel.getStraight_left_line();
	straight_parameter.dashed_line = mParameterModel.getStraight_dashed_line();
	straight_parameter.right_line = mParameterModel.getStraight_right_line();

}

void ImageProcessing::getCurveParameters() {

	curve_parameter.curve_radius = mParameterModel.getCurve_radius();
	curve_parameter.track_width_left = mParameterModel.getCurve_track_width_left(); 
	curve_parameter.track_width_right = mParameterModel.getCurve_track_width_right(); 
	curve_parameter.dashed_length = mParameterModel.getCurve_dashed_length();
	curve_parameter.dashed_space = mParameterModel.getCurve_dashed_space();
	curve_parameter.line_width = mParameterModel.getCurve_line_width();
	curve_parameter.curved_angle_start = mParameterModel.getCurve_angle_start(); 
	curve_parameter.curved_angle_end = mParameterModel.getCurve_angle_end();
	curve_parameter.dashed_middle = mParameterModel.getCurve_dashed_middle();
	curve_parameter.subdivisions = mParameterModel.getCurve_subdivisions();

}


void ImageProcessing::getEngineParameters() {

	engine_parameter.vehicle_to_camera_parameter = {
		(mParameterModel.getCameraSystemTranslationX()-10000)/1000.0,
		(mParameterModel.getCameraSystemTranslationY()-10000)/1000.0,
		(mParameterModel.getCameraSystemTranslationZ()-10000)/1000.0,
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationRoll()/10.0),
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationPitch()/10.0),
		DEG_TO_RAD(mParameterModel.getCameraSystemRotationYaw()/10.0)
	};
 
	engine_parameter.vehicle_to_cube_parameter = {
		(mParameterModel.getCubeSystemTranslationX()-10000)/1000.0,
		(mParameterModel.getCubeSystemTranslationY()-10000)/1000.0,
		(mParameterModel.getCubeSystemTranslationZ()-10000)/1000.0,
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationRoll()/10.0),
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationPitch()/10.0),
		DEG_TO_RAD(mParameterModel.getCubeSystemRotationYaw()/10.0)
	};

    engine_parameter.ui_parameter = {
		static_cast<bool>(mParameterModel.getCubeSystemNormals()),
		static_cast<bool>(mParameterModel.getCubeSystemPoints()),
		static_cast<bool>(mParameterModel.getCubeSystemFaces())
    };

}

}
