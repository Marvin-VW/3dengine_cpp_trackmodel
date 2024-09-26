// Copyright (C) 2024 twyleg
#include <engine3d/ui/ui.h>
#include <engine3d/ui/model.h>
#include <engine3d/core/image_processing.h>

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE(ui);

	engine3d::ui::UI ui(argc, argv);

	auto& imageModel = ui.getImageModel();
	auto& parameterModel = ui.getParameterModel();

	engine3d::core::ImageProcessing imageProcessing(imageModel, parameterModel);


	imageProcessing.start();
    return ui.run();
}
