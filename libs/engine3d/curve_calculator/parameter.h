// Copyright (C) 2024 Marvin-VW
#pragma once

namespace engine3d::curve_calculator::parameter {

struct CurveParameter {
		double curve_radius;
		double line_width;
		double track_width_left; 
		double track_width_right; 
		double dashed_length;
		double dashed_space;
		double curved_angle_start; 
		double curved_angle_end;
		bool dashed_middle;
		int subdivisions;
};

}