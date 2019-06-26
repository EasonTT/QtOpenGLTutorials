#include "Tutorial4.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSurfaceFormat format;
	format.setSamples(16);
	format.setDepthBufferSize(24);
	QSurfaceFormat::setDefaultFormat(format);

	Tutorial4 w;
	w.show();
	return a.exec();
}
