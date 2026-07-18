#include <QApplication>
#include "Application.h"


int main(int argc , char *argv[])
{

	QApplication app(argc, argv);

	Application application;

	application.Initialize();

	return app.exec();
}