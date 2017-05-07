#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "tools.h"
#include "mainwidget.h"



MainWindow::MainWindow()
{
	pvbox = new QVBoxLayout;

	//pp = (unsigned char *)malloc(240 * 180 * 3 * sizeof(char));

	//frame = new QImage(pp,240,180,QImage::Format_RGB888);
	frame = new QImage;

	camlabel = new QLabel;
	pexit = new QPushButton(QObject::tr("Quit"));
	pcapture = new QPushButton(QObject::tr("Capture"));

	pvbox = new QVBoxLayout;
	camlabel->resize(240,180);
	camlabel->setScaledContents(true);
	pvbox->addWidget(camlabel);
	pvbox->addWidget(pexit);

	this->setLayout(pvbox);
		
	len = 0;
	
	video = new VideoDevice(QObject::tr("/dev/video0"));
	QObject::connect(video,SIGNAL(display_error(QString)),this,SLOT(slot_display_error(QString)));
	QObject::connect(pexit,SIGNAL(clicked()),this,SLOT(slot_exit()));
	QObject::connect(pcapture,SIGNAL(clicked()),this,SLOT(slot_capture()));

	video->open_device();
	video->init_device();
	video->start_capturing();
	camtimer = new QTimer(this);
	QObject::connect(camtimer,SIGNAL(timeout()),this,SLOT(update()));

	create_video_flag = false;
	log = fopen("./log.txt","a");
	if(log == NULL)
	{
		cout<<"create log file failed: "<<strerror(errno)		<<endl;
		exit(-1);
	}
	create_video_flag = false;
	record_image_count = 0;
	fps = 5;
	video_size = CvSize(240,180);
	QObject::connect(this,SIGNAL(signal_create_writer()),this,SLOT(slot_create_writer()));

	camtimer->start(30);
	qDebug()<<"init finish!\n"<<endl;
	
}
void MainWindow::slot_create_writer()
{
	writer = new VideoWriter(videoname,CV_FOURCC('M', 'J', 'P', 'G'),fps,video_size); //创建视频文件  
	if(writer == NULL) 
	{
		cout<<"create video write failed"<<endl;		
		exit(-1);
	}
}
void MainWindow::paintEvent(QPaintEvent *)
{
	qDebug()<<"get frame begine...."<<endl;
    video->get_frame((void **)&p,&len);
	qDebug()<<"get frame finish!"<<endl;
    pp = p;
	//detect the walk 
#if 1
	//create MAT with the data pointed by @p
	Mat img(240,180,CV_8UC3,pp);
	Mat source_image = img;
	int walker_number = detect_walker(img);
	if(walker_number > 0)
	{
		//show the image that labels the walked with the rectangle
    	frame->loadFromData(img.data,240 * 180 * 3 * sizeof(char),"JPG");
    	camlabel->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));
		if(create_video_flag == false)
		{
			//set the number of images that will be saved into the video	
			record_image_count = 20;
			setCurrentVideoFileName(videoname,30);
			cout<<"video will be saved in the "<<videoname<<endl;
			emit signal_create_writer();
			//record the time into the log file

			time_t rawtime;
			struct tm* timeinfo;	
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			fprintf(log,"%s\n",asctime(timeinfo));
			//set record video flag
			create_video_flag = true;
		}
	}
	else
	{
		frame->loadFromData(source_image.data,240 * 180 * 3 * sizeof(char),"JPG");
    	camlabel->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));

	}

	if(create_video_flag)
	{
		record_image_count--;
		if(record_image_count < 0)	
		{
			//relase the writer and stop recording video		
			create_video_flag = false;
			record_image_count = 0;
			end_write_video(writer);
		}
		//record the video
		wirte_video(img,writer);
	}

#endif
    video->unget_frame();    
	qDebug()<<"unget frame finish!"<<endl;
}
void MainWindow::slot_display_error(QString text)
{
    qDebug()<<"Error: "<<text<<endl;
	exit(-1);
}

void MainWindow::slot_exit()
{
	video->uninit_device();
	video->close_device();
	free(pp);
	exit(0);
}
void MainWindow::slot_capture()
{
 QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/jana/untitled.png",tr("Images (*.png *.jpg)"));	

}


