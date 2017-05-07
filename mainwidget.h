#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QtGui>
#include <QtCore>
#include "tools.h"
#include "videodevice.h"

class MainWindow: public QWidget{
	Q_OBJECT
	private:
		QVBoxLayout *pvbox;
		QImage *frame;
		QTimer *camtimer;
		QLabel *camlabel;
		QPushButton *pexit;
		QPushButton *pcapture;
		uchar*pp;
		uchar *p;
		size_t len;
		VideoDevice *video;

		bool create_video_flag;
		FILE *log;
		int record_image_count;
		double fps;
		CvSize video_size;
		VideoWriter* writer;
		char videoname[30];

	public:
		MainWindow();
	public slots:
		void slot_display_error(QString);
		void slot_exit();
		void slot_capture();
		void slot_create_writer();
		void paintEvent(QPaintEvent *);
	signals:
		void signal_create_writer();
		
		
};




#endif
