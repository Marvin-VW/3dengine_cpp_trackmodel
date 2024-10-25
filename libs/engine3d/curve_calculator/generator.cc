// Copyright (C) 2024 Marvin-VW
#include "parameter.h"	
#include "arc_algorithm.h"

engine3d::curve_calculator::Curve curve;

namespace curve_parameter = engine3d::curve_calculator::parameter;

std::vector<triangle> generateTrack(curve_parameter::CurveParameter curve_parameter) {

    curve.generate_curve(
        0, 
        0, 
        0,
        curve_parameter.curve_radius, 
        curve_parameter.line_width, 
        curve_parameter.dashed_length, 
        curve_parameter.dashed_space, 
        curve_parameter.curved_angle_start, 
        curve_parameter.curved_angle_end, 
        false, 
        curve_parameter.subdivisions);
    
    std::vector<triangle> mesh = curve.get_curve_mesh();

	curve.generate_curve(
        0, 
        0, 
        0,
        (curve_parameter.curve_radius-curve_parameter.track_width_left), 
        curve_parameter.line_width, 
        curve_parameter.dashed_length, 
        curve_parameter.dashed_space, 
        curve_parameter.curved_angle_start, 
        curve_parameter.curved_angle_end, 
        curve_parameter.dashed_middle, 
        curve_parameter.subdivisions);
    
    std::vector<triangle> mesh2 = curve.get_curve_mesh();

	mesh.insert(mesh.end(), mesh2.begin(), mesh2.end());


	curve.generate_curve(
        0, 
        0, 
        0,
        (((curve_parameter.curve_radius-curve_parameter.track_width_left)-(curve_parameter.line_width))-curve_parameter.track_width_right), 
        curve_parameter.line_width, 
        curve_parameter.dashed_length, 
        curve_parameter.dashed_space, 
        curve_parameter.curved_angle_start, 
        curve_parameter.curved_angle_end, 
        false,
        curve_parameter.subdivisions);
    
    std::vector<triangle> mesh3 = curve.get_curve_mesh();
    
	mesh.insert(mesh.end(), mesh3.begin(), mesh3.end());

    return mesh;

}