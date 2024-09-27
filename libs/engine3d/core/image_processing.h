// Copyright (C) 2024 twyleg
#pragma once
#include <QThread>
#include <QPixmap>

#include <engine3d/ui/model.h>

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
	std::vector<double> getTrackbars();

};

}
