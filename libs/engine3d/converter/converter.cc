#include "converter.h"

Converter::Converter(cv::Mat& I_T_C) : I_T_C(I_T_C) {
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

void Converter::computeCubePoints(cv::Mat& C_T_V) {

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


        std::cout << rhoWidth << "rhoWidth" <<std::endl;




    // Original matrices
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

    // Compute the pseudoinverse of matrixC
    cv::Mat matrixC_pseudoInv;
    cv::invert(matrixC, matrixC_pseudoInv, cv::DECOMP_SVD);
    

    // Print results
    std::cout << "Inverse of matrixK:\n" << matrixK_inv << std::endl;
    std::cout << "Pseudoinverse of matrixC:\n" << matrixC_pseudoInv << std::endl;



    for (auto& point : image_points) {


        // Example 2D point in homogeneous coordinates
        cv::Mat point2D = createPointTemp(point.x, point.y, 1);


        // Reconstruct 3D point
        cv::Mat point3D_homo = matrixC_pseudoInv * (matrixK_inv * point2D);

        std::cout << "Reconstructed 3D point:\n" << point3D_homo << std::endl;

        cv::Mat point3D = point3D_homo * 0.335;

        std::cout << "Reconstructed 3D point:\n" << point3D.t() << std::endl;

    }







/*

    cv::Mat C_T_V_4x4_inv = C_T_V.inv();

    cv::Mat pseudoinverse_I_T_C;
    cv::invert(I_T_C, pseudoinverse_I_T_C, cv::DECOMP_SVD); //Pseudoinverse

        std::cout << I_T_C << std::endl;

        std::cout << pseudoinverse_I_T_C << std::endl;


        	double test[3*4] =  {	0.001765625,	0,					-0.564999999999999,
									0,	0.001765625,		-0.4237499999999999,
									0,	0,		1,
									0,	0,	0,};	


            cv::Mat test1(3,4,CV_64F,test);


    for (auto& point : image_points) {


        std::cout << point.x << " " << point.y <<std::endl;


        cv::Mat base_point_temp = createPoint(point.x, point.y, 1);
        cv::Mat converted_point_test = test1 * base_point_temp;

        converted_point_test.at<double>(3, 0) = 1;

        double w = converted_point_test.at<double>(3, 0);
        if (w != 0.0) {
            converted_point_test * 1;
        }

        std::cout << "pseudoinverse_I_T_C" << converted_point_test*0.14 << std::endl;


        //cv::Mat converted_world_test = C_T_V_4x4_inv * converted_point_test;

        //std::cout << "C_T_V_4x4_inv" << converted_world_test << std::endl;

        engine_points.push_back(converted_point_test);
    }

    */



}

std::vector<cv::Mat> Converter::getConvertedPoints() {
    return engine_points;
}
