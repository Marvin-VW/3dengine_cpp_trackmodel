#include "trackmodel.h"

namespace engine3d::trackmodel {

Trackmodel::Trackmodel(
    engine3d::ui::ParameterModel& parameterModel) : 
    mParameterModel(parameterModel),
    convert_to_engine()
{}

void Trackmodel::trackmodel_position(
    std::vector<triangle> mesh, 
    std::vector<image_filter::line_pair> detected_pairs) 
    
{

		std::vector<cv::Point> image_points;
		for (int i = 0; i < detected_pairs.size(); i++) {
			image_points.push_back(detected_pairs[i].pair_left.start_point);
			image_points.push_back(detected_pairs[i].pair_left.end_point);
			image_points.push_back(detected_pairs[i].pair_right.start_point);
			image_points.push_back(detected_pairs[i].pair_right.end_point);
		}


		if (mesh.size() > 1) {
			std::cout << "(" << mesh[0].camera_points[0] << ")\n";
        	std::cout << "(" << mesh[1].camera_points[0] << ")\n";
        	std::cout << "(" << mesh[2].camera_points[0] << ")\n";
        	std::cout << "(" << mesh[3].camera_points[0] << ")\n";
		}


		convert_to_engine.setBasePoints(image_points);
        convert_to_engine.computeCubePoints();
        std::vector<cv::Mat> points_camera_reverse = convert_to_engine.getConvertedPoints();


		//links 
		//abstände


		//filtern wo die linien sein könnten (5 kontrollreihen und 3 ausgangsreihen)

		//wir nehmen uns die ausgangsreihen und legen ein spurmodell an ->vorher sollte kontrolliert werden ob der abstand ungefähr passt (mit der richtigen verschiebung)
		//dann wird überprüft wie viele punkte der kontrollreihen innerhalb des spurmodells an den kontrollreihen anliegen
		//das spurmodell mit den meisten kontrollreihen wird ausgegeben als richtiges

		//instanz converter
		//koordinaten der reihen (8 reihen)

		//1. 3 ausgangsreihen -> abstand kontrollieren
		//2. 3 ausgangsreihen -> richtig verschieben
		//3. überprüfen wie viele punkte der kontrollreihen innerhalb der spurmodellausgangsreihen liegen
		//4. beste werte ausgeben

		if (mesh.size() > 1) {
			// Calculate distances
			float distance_1 = abs(mesh[2].camera_points[0].at<double>(0) - points_camera_reverse[0].at<double>(0));
			float distance_2 = abs(mesh[3].camera_points[0].at<double>(0) - points_camera_reverse[1].at<double>(0));

			std::cout << "dif " << distance_1 << " " << distance_2 << "\n";

			// Threshold for distance comparison
			const float threshold = 0.1;  // Adjust based on your requirements

			if (distance_1 < threshold && distance_2 < threshold) {
				// Both distances are small -> too far to one side
				if (distance_1 < distance_2) {
					std::cout << "Too far right, moving left.\n";
					mParameterModel.setCubeSystemTranslationX(mParameterModel.getCubeSystemTranslationX() - 0.1);
				} else if (distance_1 > distance_2) {
					std::cout << "Too far left, moving right.\n";
					mParameterModel.setCubeSystemTranslationX(mParameterModel.getCubeSystemTranslationX() + 0.1);
				}
			} else {
				// One distance is smaller -> find the center
				if (distance_1 < distance_2) {
					std::cout << "Adjusting slightly right to find center.\n";
					mParameterModel.setCubeSystemTranslationX(mParameterModel.getCubeSystemTranslationX() + 0.05);
				} else {
					std::cout << "Adjusting slightly left to find center.\n";
					mParameterModel.setCubeSystemTranslationX(mParameterModel.getCubeSystemTranslationX() - 0.05);
				}
			}
		}



}



}
