#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QtGui>
#include <QtCore>
#include "videodevice.h"

class MainWindow: public QWidget{
	Q_OBJECT
	private:
		QVBoxLayout *pvbox;
		QImage *frame;
		QTimer *camtimer;
		QLabel *camlabel;
		QPushButton *pexit;

		uchar*pp;
		uchar *p;
		
		size_t len;

		VideoDevice *video;
	public:
		MainWindow();
	public slots:
		void slot_display_error(QString);
		void slot_exit();
		void paintEvent(QPaintEvent *);
		
		
};




#endif
