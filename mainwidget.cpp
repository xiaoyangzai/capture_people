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

	pvbox = new QVBoxLayout;
	//camlabel->resize(320,240);
	camlabel->setScaledContents(true);
	pvbox->addWidget(camlabel);
	pvbox->addWidget(pexit);

	this->setLayout(pvbox);
		
	len = 0;
	
	QObject::connect(pexit,SIGNAL(clicked()),this,SLOT(slot_exit()));

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
	video_size = CvSize(640,480);
	QObject::connect(this,SIGNAL(signal_create_writer()),this,SLOT(slot_create_writer()));

	camtimer->start(30);
	qDebug()<<"init finish!\n"<<endl;
	cam = cvCreateCameraCapture(0);
	
}
void MainWindow::slot_create_writer()
{
	writer = init_video_infomation(videoname,video_size,fps); //创建视频文件  
	if(writer == NULL) 
	{
		cout<<"create video write failed"<<endl;		
		exit(-1);
	}
}
void MainWindow::paintEvent(QPaintEvent *)
{
	IplImage *frame = cvQueryFrame(cam);//从摄像头或者文件中抓取并返回一帧  
	Mat img = cvarrToMat(frame);
	Mat temp_img;
	int walker_number = detect_face(img);
	cvtColor(img, temp_img, CV_BGR2RGB); 
	if(walker_number > 0)
	{
#if 1
		if(create_video_flag == false)
		{
			cout<<"there have "<<walker_number<<"people under tht monitor"<<endl;
			//set the number of images that will be saved into the video	
			record_image_count = 50;
			setCurrentVideoFileName(videoname,30);
			cout<<"video will be saved in the "<<videoname<<endl;
			emit signal_create_writer();
			//record the time into the log file

			time_t rawtime;
			struct tm* timeinfo;	
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			//set record the log
			fprintf(log,"== %s == \t%d people are detected!!=================\n",asctime(timeinfo),walker_number);
			//set record video flag
			create_video_flag = true;
		}
	}
	QImage temp((const uchar*)temp_img.data, temp_img.cols,temp_img.rows,QImage::Format_RGB888);  
	camlabel->setPixmap(QPixmap::fromImage(temp));

	if(create_video_flag)
	{
		record_image_count--;
		if(record_image_count < 0)	
		{
			//relase the writer and stop recording video		
			create_video_flag = false;
			record_image_count = 0;
			end_write_video(writer);
			cout<<"record video finished!!!!\n";
		}
		else
		{
			//record the video
			cout<<"record into the video....\n";
			wirte_video(img,writer);
		}
	}

#endif
}
void MainWindow::slot_display_error(QString text)
{
    qDebug()<<"Error: "<<text<<endl;
	exit(-1);
}

void MainWindow::slot_exit()
{
	fclose(log);
	cvReleaseCapture(&cam);
	exit(0);
}


