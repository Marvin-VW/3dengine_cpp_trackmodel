// Copyright (C) 2024 Marvin-VW
#pragma once

#include "triangle.h"
#include "parameter.h"
#include "homogenous_transformation_matrix.h"

#include <cstdint>

namespace parameter = engine3d::engine::parameter;

class Shape;
class CameraModel;
class HomogenousTransformationMatrix;
class FpsCounter;
class ClippingSpace;
class Vectors;
class Color;

class RenderSystem
{
public:
    RenderSystem(
    CameraModel& cameraModel, 
    Shape& Shape, 
    ClippingSpace& ClippingSpace,
    Vectors& Vectors,
    Color& Color,
    FpsCounter& FpsCounter
    );

    void create_matrices(const parameter::Parameter parameter);
    void update_fps();

    cv::Mat renderFrame();
    // void update_movement(int key);

public:
    CameraModel& mCameraModel;

private:
    friend class Shape;
    friend class HomogenousTransformationMatrix;
    friend class FpsCounter;
    friend class Vectors;
    friend class Color;
private:
    std::vector<triangle> mesh;
private:
    Shape& mShape;
    ClippingSpace& mClippingSpace;
    Vectors& mVectors;
    Color& mColor;
    FpsCounter& mFpsCounter;
};
