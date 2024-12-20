// Copyright (C) 2024 Marvin-VW
#include "engine.h"

#include <cmath>
#include <iostream>


namespace engine3d::engine {

namespace engine_parameter = engine3d::engine::parameter;

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))

double Engine::is_triangle_facing_camera(triangle& tri, cv::Vec3d cam) {

    double dot_product =   tri.normal.at<double>(0) * (tri.centroid.at<double>(0) - cam[0]) +
                           tri.normal.at<double>(1) * (tri.centroid.at<double>(1) - cam[1]) +
                           tri.normal.at<double>(2) * (tri.centroid.at<double>(2) - cam[2]);

    return dot_product;
};


Engine::Engine(int frame_width, int frame_height)
    : camera(0.00452, 0.00339, 0.004, frame_width, frame_height, frame_width / 2, frame_height / 2),
      shape(),
      clipping(),
      vector(),
      color(),
      fps(60),
      renderer(camera, shape, clipping, vector, color, fps)
{

    //generate cube mesh
    //mesh = shape.generate_mesh(1, 1, 1);

}

Engine::~Engine()
{
}


cv::Mat Engine::run(cv::Mat& frame, std::vector<triangle>& mesh, const engine_parameter::Parameter parameter)
{

    camera.resetCameraImage(frame);

    renderer.create_matrices(parameter);
    cv::Vec3d camera_vector_world = camera.getCameraVector(camera.V_T_C);

    std::vector<triangle> visiable_mesh;

    for (auto& tri : mesh) {

        camera.world_transform(&camera.V_T_Cube, &tri);
        camera.camera_transform(&camera.C_T_V, &tri);

        std::tuple<cv::Mat, cv::Mat> result = vector.normal(tri, 0.5f);

        cv::Mat normal_start = std::get<0>(result);
        cv::Mat normal_end = std::get<1>(result);
        cv::Mat normal_start_camera = camera.C_T_V * normal_start;
        cv::Mat normal_end_camera = camera.C_T_V * normal_end;

        //backface culling
        if (is_triangle_facing_camera(tri, camera_vector_world) < 0.0) {

            if (parameter.ui_parameter.showNormals == 1)
                camera.drawCameraImageArrow(normal_start_camera, normal_end_camera);

            cv::Vec3d light_direction(1.0f, 0.0f, 0.0f);
            cv::Scalar base_color(0, 153, 255);

            tri.ilm = color.intensity(light_direction, tri.normal);
            tri.color = color.adjust_bgr_intensity(base_color, tri.ilm);

            visiable_mesh.push_back(tri);

        }

        std::cout << "CameraPoints: " << tri.camera_points[0] << std::endl;
        std::cout << "CameraPoints: " << tri.camera_points[1] << std::endl;
        std::cout << "CameraPoints: " << tri.camera_points[2] << std::endl;
        
    }

    std::cout << "-----------------------------------------" << std::endl;

    //clipping
    std::vector<triangle> clipped_mesh;
    clipped_mesh = clipping.cubeInSpace(&visiable_mesh);

    camera.drawAllLines(&mesh);
    if (parameter.ui_parameter.showPoints == 1)
    {
        camera.drawAllPoints(&mesh);
    }

    if (parameter.ui_parameter.showFaces == 1)
    {
            camera.fillCubeFaces(&visiable_mesh);
    }
    
    
    renderer.update_fps();
    engine_frame = renderer.renderFrame();

    return engine_frame;

}

}
