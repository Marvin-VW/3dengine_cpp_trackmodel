// Copyright (C) 2024 Marvin-VW
#pragma once

#include "shape.h"

#include <cstdint>



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

    void create_matrices(std::vector<double> trackbarPos);
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
