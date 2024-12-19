#include "converter.h"

Converter::Converter() {
}


cv::Mat Converter::createPoint(double x, double y, double z) {
    cv::Mat point(4,1,CV_64F);
    point.at<double>(0) = x;
    point.at<double>(1) = y;
    point.at<double>(2) = z;
    point.at<double>(3) = 1;
    return point;
}

cv::Mat Converter::createPointTemp(double x, double y, double z) {
    cv::Mat point(3,1,CV_64F);
    point.at<double>(0) = x;
    point.at<double>(1) = y;
    point.at<double>(2) = z;
    point.at<double>(3) = 1;
    return point;
}


void Converter::setBasePoints(std::vector<cv::Point>& image_points) {
    this->image_points = image_points;
}

void Converter::computeCubePoints() {

    engine_points.clear();

    double sensorWidth = 0.00452;
    double sensorHeight = 0.00339;
    double focalLength = 0.004;
    uint32_t resolutionX = 640;
    uint32_t resolutionY = 480;
    uint32_t u0 = 640/2;
    uint32_t v0 = 480/2;

    const double rhoWidth = sensorWidth / resolutionX;
    const double rhoHeight = sensorHeight / resolutionY;

    double matrixK_data[3 * 3] = {
        (1 / rhoWidth), 0, static_cast<double>(u0),
        0, (1 / rhoHeight), static_cast<double>(v0),
        0, 0, 1
    };

    double matrixC_data[3 * 4] = {
        focalLength, 0, 0, 0,
        0, focalLength, 0, 0,
        0, 0, 1, 0
    };

    cv::Mat matrixK(3, 3, CV_64F, matrixK_data);
    cv::Mat matrixC(3, 4, CV_64F, matrixC_data);

    // Invert matrixK
    cv::Mat matrixK_inv = matrixK.inv();

    //pseudoinverse of matrixC
    cv::Mat matrixC_pseudoInv;
    cv::invert(matrixC, matrixC_pseudoInv, cv::DECOMP_SVD);
    
    for (auto& point : image_points) {

        cv::Mat point2D = createPointTemp(point.x, point.y, 1);

        // Reconstruct 3D point
        cv::Mat point3D_homo = matrixC_pseudoInv * (matrixK_inv * point2D);

        double simulated_z = 0.14 / point3D_homo.at<double>(1) ;
        cv::Mat point3D = point3D_homo * (-simulated_z);

        std::cout << "Reconstructed 3D point:\n" << point3D.t() << std::endl;

        point3D.at<double>(3) = 1;

        engine_points.push_back(point3D);
    }

}

std::vector<cv::Mat> Converter::getConvertedPoints() {
    return engine_points;
}
