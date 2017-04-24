#include <QApplication>
#include <QtGui>
#include "mainwidget.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	MainWindow mwin;
	mwin.show();


	return app.exec();
}
