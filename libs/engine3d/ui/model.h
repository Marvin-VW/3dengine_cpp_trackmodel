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
    ADD_PROPERTY(double, cameraSystemTranslationX, CameraSystemTranslationX, 10000.0)
    ADD_PROPERTY(double, cameraSystemTranslationY, CameraSystemTranslationY, 10130.0)
    ADD_PROPERTY(double, cameraSystemTranslationZ, CameraSystemTranslationZ, 10150.0)
    ADD_PROPERTY(double, cameraSystemRotationRoll, CameraSystemRotationRoll, 2700.0)
    ADD_PROPERTY(double, cameraSystemRotationPitch, CameraSystemRotationPitch, 0.0)
    ADD_PROPERTY(double, cameraSystemRotationYaw, CameraSystemRotationYaw, 2700.0)
    ADD_PROPERTY(double, cubeSystemTranslationX, CubeSystemTranslationX, 10400.0)
    ADD_PROPERTY(double, cubeSystemTranslationY, CubeSystemTranslationY, 10130.0)
    ADD_PROPERTY(double, cubeSystemTranslationZ, CubeSystemTranslationZ, 10080.0)
    ADD_PROPERTY(double, cubeSystemRotationRoll, CubeSystemRotationRoll, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationPitch, CubeSystemRotationPitch, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationYaw, CubeSystemRotationYaw, 0.0)
    ADD_PROPERTY(int, cubeSystemScale, CubeSystemScale, 0.0)
    ADD_PROPERTY(int, cubeSystemNormals, CubeSystemNormals, 0.0)
    ADD_PROPERTY(int, cubeSystemPoints, CubeSystemPoints, 0.0)
    ADD_PROPERTY(int, cubeSystemFaces, CubeSystemFaces, 0.0)


	//curve
	ADD_PROPERTY(int, showCurve, ShowCurve, 0.0)
	ADD_PROPERTY(double, curve_radius, Curve_radius, 1.5)
	ADD_PROPERTY(double, line_width, Line_width, 0.02)
    ADD_PROPERTY(double, track_width, Track_width, 0.36)
    ADD_PROPERTY(double, dashed_length, Dashed_length, 0.18)
    ADD_PROPERTY(double, dashed_space, Dashed_space, 0.16)
    ADD_PROPERTY(double, curved_angle_start, Curved_angle_start, 0.0)
    ADD_PROPERTY(double, curved_angle_end, Curved_angle_end, 90.0)
	ADD_PROPERTY(int, dashed_middle, Dashed_middle, 0.0)
    ADD_PROPERTY(int, dashed_outer, Dashed_outer, 0.0)
    ADD_PROPERTY(int, subdivisions, Subdivisions, 20.0)

	//straight
	ADD_PROPERTY(int, showStraight, ShowStraight, 0.0)
	ADD_PROPERTY(double, length, Length, 0.35)
	ADD_PROPERTY(double, width, Width, 0.015)
	ADD_PROPERTY(double, stripeNumber, StripeNumber, 5)
	ADD_PROPERTY(double, stripeLength, StripeLength, 0.035)
	ADD_PROPERTY(double, lineDistance, LineDistance, 0.1)
	ADD_PROPERTY(double, leftLine, LeftLine, 1.0)
	ADD_PROPERTY(double, stripedLine, StripedLine, 1.0)
    ADD_PROPERTY(double, rightLine, RightLine, 1.0)


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
