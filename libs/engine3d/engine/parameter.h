// Copyright (C) 2024 Marvin-VW
#pragma once

namespace engine3d::engine::parameter {

	struct MatrixParameter {
		double transX;
		double transY;
		double transZ;
		double rotRoll;
		double rotPitch;
		double rotYaw;
	};

	struct UIParameter {
		bool showNormals;
		bool showPoints;
		bool showFaces;
	};

	struct Parameter {

		MatrixParameter vehicle_to_camera_parameter;
		MatrixParameter vehicle_to_cube_parameter;
		UIParameter ui_parameter;

	};

}