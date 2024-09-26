// Copyright (C) 2024 twyleg
#include "ui.h"

#include <QQmlContext>

#include <boost/optional.hpp>
#include <fmt/core.h>

namespace engine3d::ui {

UI::UI(int argc, char **argv) :
	QQuickImageProvider(QQuickImageProvider::Pixmap),
    mArgc(argc),
    mArgv(argv),
	mApplication(mArgc, mArgv)
{}

UI::~UI() {}

QPixmap UI::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
   return mImageModel.getImage();
}

int UI::run() {

	mEngine.rootContext()->setContextProperty("imageModel", &mImageModel);
	mEngine.rootContext()->setContextProperty("parameterModel", &mParameterModel);
	mEngine.addImageProvider("stream", this);

	mEngine.addImportPath("qrc:/");
	mEngine.load("qrc:/frontend/qml/MainWindow.qml");

    return mApplication.exec();
}

}
