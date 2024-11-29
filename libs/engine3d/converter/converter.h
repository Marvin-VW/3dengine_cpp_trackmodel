#pragma once 

#include <opencv2/opencv.hpp>
#include <vector>
#include <stdexcept>
#include "engine3d/engine/triangle.h"

class Converter {
public:
    Converter(cv::Mat& I_T_C);
    void setBasePoints(std::vector<cv::Point>& image_points);
    void computeCubePoints(cv::Mat& C_T_V);
    std::vector<cv::Mat> getConvertedPoints();

private:
    cv::Mat createPoint(double x, double y, double z);
    cv::Mat createPointTemp(double x, double y, double z);
    cv::Mat I_T_C;
    std::vector<cv::Point> image_points;
    std::vector<cv::Mat> engine_points;
};
