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

    ADD_PROPERTY(double, cameraSystemTranslationX, CameraSystemTranslationX, 10000.0)
    ADD_PROPERTY(double, cameraSystemTranslationY, CameraSystemTranslationY, 10000.0)
    ADD_PROPERTY(double, cameraSystemTranslationZ, CameraSystemTranslationZ, 10000.0)
    ADD_PROPERTY(double, cameraSystemRotationRoll, CameraSystemRotationRoll, 2700.0)
    ADD_PROPERTY(double, cameraSystemRotationPitch, CameraSystemRotationPitch, 0.0)
    ADD_PROPERTY(double, cameraSystemRotationYaw, CameraSystemRotationYaw, 2700.0)
    ADD_PROPERTY(double, cubeSystemTranslationX, CubeSystemTranslationX, 16000.0)
    ADD_PROPERTY(double, cubeSystemTranslationY, CubeSystemTranslationY, 10000.0)
    ADD_PROPERTY(double, cubeSystemTranslationZ, CubeSystemTranslationZ, 10000.0)
    ADD_PROPERTY(double, cubeSystemRotationRoll, CubeSystemRotationRoll, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationPitch, CubeSystemRotationPitch, 0.0)
    ADD_PROPERTY(double, cubeSystemRotationYaw, CubeSystemRotationYaw, 250.0)
    ADD_PROPERTY(double, cubeSystemScale, CubeSystemScale, 0.0)
    ADD_PROPERTY(double, cubeSystemNormals, CubeSystemNormals, 0.0)
    ADD_PROPERTY(double, cubeSystemPoints, CubeSystemPoints, 0.0)
    ADD_PROPERTY(double, cubeSystemFaces, CubeSystemFaces, 1.0)


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
