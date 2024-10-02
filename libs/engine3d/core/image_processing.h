// Copyright (C) 2024 twyleg
#pragma once

#include "engine3d/engine/homogenous_transformation_matrix.h"

#include <QThread>
#include <QPixmap>

#include <engine3d/ui/model.h>

namespace HTM = engine3d::engine::homogeneous_transformation_matrix;

namespace engine3d::core {

class ImageProcessing: public QThread {

	Q_OBJECT

public:

	ImageProcessing(
		engine3d::ui::ImageModel& imageModel,
		engine3d::ui::ParameterModel& parameterModel,
		QObject* parent=nullptr
	);
	virtual ~ImageProcessing();

	void run() override;

	engine3d::ui::ImageModel& mImageModel;
	engine3d::ui::ParameterModel& mParameterModel;


private:

	QPixmap generate_test_image(int red, int green, int blue);
	 HTM::Matrix::Parameter getParameters();

};

}
