// Copyright (C) 2024 twyleg
#include "image_processing.h"

#include <engine3d/engine/engine.h>

#include <opencv2/opencv.hpp>
#include <fmt/core.h>

#include <optional>

namespace engine3d::core {

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

	int frame_width = 640;
	int frame_height = 480;

	cv::Mat camera_frame;
    cv::Mat engine_frame;

	engine3d::engine::Engine engine(frame_width, frame_height);

    bool running = true;

    while(running) {

		// double relativ_x;
		// double relativ_y;

		camera_frame = cv::Mat(frame_height, frame_width, CV_8UC3, cv::Scalar(255,255,255));

		engine_frame = engine.run(camera_frame, getTrackbars());

		QImage img((uchar*)engine_frame.data, engine_frame.cols, engine_frame.rows, QImage::Format_RGB888);
		mImageModel.setImage(QPixmap::fromImage(img));

		msleep(1000 / 60.0);

    }

}


std::vector<double> ImageProcessing::getTrackbars() {

    std::vector<double> trackbars = 
    {
        mParameterModel.getCameraSystemTranslationX(),
        mParameterModel.getCameraSystemTranslationY(),
        mParameterModel.getCameraSystemTranslationZ(),
        mParameterModel.getCameraSystemRotationRoll(),
        mParameterModel.getCameraSystemRotationPitch(),
        mParameterModel.getCameraSystemRotationYaw(),
        mParameterModel.getCubeSystemTranslationX(),
        mParameterModel.getCubeSystemTranslationY(),
        mParameterModel.getCubeSystemTranslationZ(),
        mParameterModel.getCubeSystemRotationRoll(),
        mParameterModel.getCubeSystemRotationPitch(),
        mParameterModel.getCubeSystemRotationYaw(),
        mParameterModel.getCubeSystemScale(),
        mParameterModel.getCubeSystemNormals(),
        mParameterModel.getCubeSystemPoints(),
        mParameterModel.getCubeSystemFaces()
    };

    return trackbars;
}

}
