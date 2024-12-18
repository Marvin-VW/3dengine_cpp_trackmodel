// Copyright (C) 2024 Marvin-VW
#pragma once

#include "engine3d/image_filter/camera_processor.h"
#include "engine3d/engine/triangle.h"

#include "engine3d/converter/converter.h"

#include "engine3d/ui/model.h"


#include <opencv2/opencv.hpp>


namespace image_filter = engine3d::image_filter;

namespace engine3d::trackmodel {

class Trackmodel {

public:

    Trackmodel(engine3d::ui::ParameterModel& parameterModel);

    engine3d::ui::ParameterModel& mParameterModel;

    void trackmodel_position(
        std::vector<triangle> mesh, 
        std::vector<image_filter::line_pair> detected_pairs);
    

private:

    Converter convert_to_engine;

};

}