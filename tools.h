#ifndef __TOOLS_H__
#define __TOOLS_H__
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <time.h>
using namespace cv;
using namespace std;


int detect_walker(Mat image);
void setCurrentVideoFileName(char *relust,int len);
VideoWriter* init_video_infomation(const char *filename,CvSize size,double fps);
int wirte_video(Mat &img,VideoWriter *writer);
int end_write_video(VideoWriter *writer);
int detect_face(Mat image,const char *falter);
#endif
