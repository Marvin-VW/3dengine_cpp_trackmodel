// Copyright (C) 2024 twyleg, Marvin-VW
#pragma once

#include "engine3d/engine/parameter.h"
#include "engine3d/curve_calculator/parameter.h"

#include <QThread>
#include <QPixmap>

#include <engine3d/ui/model.h>

namespace engine_parameter = engine3d::engine::parameter;
namespace curve_parameter = engine3d::curve_calculator::parameter;

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

	engine_parameter::Parameter engine_parameter;
	curve_parameter::CurveParameter curve_parameter;

	QPixmap generate_test_image(int red, int green, int blue);
	void getEngineParameters();
	void getCurveParameters();

};

}
