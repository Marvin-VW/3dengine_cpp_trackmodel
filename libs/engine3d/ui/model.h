// Copyright (C) 2024 twyleg
#pragma once

#include <fmt/core.h>

#include <QObject>
#include <QPixmap>
#include <QMutex>
#include <QMutexLocker>

namespace engine3d::ui {

#define ADD_PROPERTY(datatype, name, funcName, initial_value) \
private: \
	datatype name = initial_value; \
	Q_PROPERTY(datatype name READ get##funcName WRITE set##funcName NOTIFY  name##Changed) \
public: \
	datatype& get##funcName() { \
		QMutexLocker locker(&mMutex); \
		return name; \
	} \
	void set##funcName(const datatype& value) \
	{ \
		if (name != value) {\
			mMutex.lock(); \
			name = value; \
			mMutex.unlock(); \
			emit name##Changed(); \
		}\
	} \
Q_SIGNALS: \
	void name##Changed(); \
private: \



class ParameterModel : public QObject
{
	Q_OBJECT

private:

	QMutex mMutex;

public:

	//engine
	/*
    ADD_PROPERTY(double, cameraSystemTranslationX, CameraSystemTranslationX, 10065.0)
    ADD_PROPERTY(double, cameraSystemTranslationY, CameraSystemTranslationY, 10000.0)
    ADD_PROPERTY(double, cameraSystemTranslationZ, CameraSystemTranslationZ, 10140.0)
	*/
	ADD_PROPERTY(double, cameraSystemTranslationX, CameraSystemTranslationX, 10000.0)
    ADD_PROPERTY(double, cameraSystemTranslationY, CameraSystemTranslationY, 10140.0)
    ADD_PROPERTY(double, cameraSystemTranslationZ, CameraSystemTranslationZ, 9935.0)


    ADD_PROPERTY(double, cameraSystemRotationRoll, CameraSystemRotationRoll, 0.0)
    ADD_PROPERTY(double, cameraSystemRotationPitch, CameraSystemRotationPitch, 1800.0)
    ADD_PROPERTY(double, cameraSystemRotationYaw, CameraSystemRotationYaw, 0.0)
	/*
    ADD_PROPERTY(double, cubeSystemTranslationX, CubeSystemTranslationX, 10400.0)
    ADD_PROPERTY(double, cubeSystemTranslationY, CubeSystemTranslationY, 9850.0)
    ADD_PROPERTY(double, cubeSystemTranslationZ, CubeSystemTranslationZ, 10000.0)
	*/

	ADD_PROPERTY(double, cubeSystemTranslationX, CubeSystemTranslationX, 9850.0)
    ADD_PROPERTY(double, cubeSystemTranslationY, CubeSystemTranslationY, 10000.0)
    ADD_PROPERTY(double, cubeSystemTranslationZ, CubeSystemTranslationZ, 10400.0)


    ADD_PROPERTY(double, cubeSystemRotationRoll, CubeSystemRotationRoll, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationPitch, CubeSystemRotationPitch, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationYaw, CubeSystemRotationYaw, 0.0)
    ADD_PROPERTY(int, cubeSystemScale, CubeSystemScale, 0.0)
    ADD_PROPERTY(int, cubeSystemNormals, CubeSystemNormals, 0.0)
    ADD_PROPERTY(int, cubeSystemPoints, CubeSystemPoints, 0.0)
    ADD_PROPERTY(int, cubeSystemFaces, CubeSystemFaces, 0.0)


	//curve
	ADD_PROPERTY(int, showCurve, ShowCurve, 0.0)
	ADD_PROPERTY(double, curve_radius, Curve_radius, 1.65)
    ADD_PROPERTY(double, curve_track_width_left, Curve_track_width_left, 0.44)
    ADD_PROPERTY(double, curve_track_width_right, Curve_track_width_right, 0.39)
    ADD_PROPERTY(double, curve_dashed_length, Curve_dashed_length, 0.18)
    ADD_PROPERTY(double, curve_dashed_space, Curve_dashed_space, 0.16)
	ADD_PROPERTY(double, curve_line_width, Curve_line_width, 0.02)
    ADD_PROPERTY(double, curve_angle_start, Curve_angle_start, 0.0)
    ADD_PROPERTY(double, curve_angle_end, Curve_angle_end, 90.0)
	ADD_PROPERTY(int, curve_dashed_middle, Curve_dashed_middle, 0.0)
    ADD_PROPERTY(int, curve_dashed_outer, Curve_dashed_outer, 0.0)
    ADD_PROPERTY(int, curve_subdivisions, Curve_subdivisions, 20.0)

	//straight
	ADD_PROPERTY(int, showStraight, ShowStraight, 0.0)
	ADD_PROPERTY(double, straight_track_length, Straight_track_length, 0.5)
	ADD_PROPERTY(double, straight_track_width_left, Straight_track_width_left, 0.28)
	ADD_PROPERTY(double, straight_track_width_right, Straight_track_width_right, 0.26)
	ADD_PROPERTY(double, straight_stripeNumber, Straight_stripeNumber, 5)
	ADD_PROPERTY(double, straight_stripeLength, Straight_stripeLength, 0.035)
	ADD_PROPERTY(double, straight_line_width, Straight_line_width, 0.02)
	ADD_PROPERTY(double, straight_left_line, Straight_left_line, 1.0)
	ADD_PROPERTY(double, straight_dashed_line, Straight_dashed_line, 1.0)
    ADD_PROPERTY(double, straight_right_line, Straight_right_line, 1.0)


Q_SIGNALS:

	void parameterChanged();

};

class ImageModel : public QObject
{
	Q_OBJECT

private:

	QMutex mMutex;
	QPixmap image;
	Q_PROPERTY(QPixmap image READ getImage WRITE setImage NOTIFY imageChanged)


public:

	const QPixmap& getImage() {
		QMutexLocker locker(&mMutex);
		return image;
	}
	void setImage(const QPixmap& image) {
		mMutex.lock();
		this->image = image;
		mMutex.unlock();
		emit imageChanged();
	}

Q_SIGNALS:

	void imageChanged();

};

}
