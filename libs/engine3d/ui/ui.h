// Copyright (C) 2024 twyleg
#pragma once

#include "model.h"

#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickImageProvider>

namespace engine3d::ui {

class UI: public QQuickImageProvider  {

Q_OBJECT

public:

	UI(int argc, char** argv);
    virtual ~UI();

	QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;

	ImageModel& getImageModel() { return mImageModel; }
	ParameterModel& getParameterModel() { return mParameterModel; }

	int run();

private:

    int mArgc;
    char **mArgv;

    QApplication mApplication;
    QQmlApplicationEngine mEngine;

	ImageModel mImageModel;
	ParameterModel mParameterModel;

};


}
