#include <stdlib.h>
#include "mainwidget.h"



MainWindow::MainWindow()
{
	pvbox = new QVBoxLayout;

	//pp = (unsigned char *)malloc(240 * 180 * 3 * sizeof(char));

	//frame = new QImage(pp,240,180,QImage::Format_RGB888);
	frame = new QImage;

	camlabel = new QLabel;
	pexit = new QPushButton(QObject::tr("quit"));

	pvbox = new QVBoxLayout;
	camlabel->resize(240,180);
	camlabel->setScaledContents(true);
	pvbox->addWidget(camlabel);
	pvbox->addWidget(pexit);

	this->setLayout(pvbox);
	
	len = 0;
	
	video = new VideoDevice(QObject::tr("/dev/video0"));
	QObject::connect(video,SIGNAL(display_error(QString)),this,SLOT(slot_display_error(QString)));

	video->open_device();
	video->init_device();
	video->start_capturing();
	camtimer = new QTimer(this);
	QObject::connect(camtimer,SIGNAL(timeout()),this,SLOT(update()));
	camtimer->start(30);
	qDebug()<<"init finish!\n"<<endl;
	

	
}
void MainWindow::paintEvent(QPaintEvent *)
{
	qDebug()<<"get frame begine...."<<endl;
    video->get_frame((void **)&p,&len);
	qDebug()<<"get frame finish!"<<endl;
    pp = p;
    frame->loadFromData((uchar *)pp,240 * 180 * 3 * sizeof(char),"JPG");
    camlabel->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));
    video->unget_frame();    
	qDebug()<<"unget frame finish!"<<endl;
}
void MainWindow::slot_display_error(QString text)
{
    qDebug()<<"Error: "<<text<<endl;
}

void MainWindow::slot_exit()
{
	video->uninit_device();
	video->close_device();
	free(pp);
}


