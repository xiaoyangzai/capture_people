#ifndef __TOOLS_H__
#define __TOOLS_H__
#include <iostream>
#include <string.h>
#include <imgcodecs.hpp>
#include <highgui.hpp>
#include <objdetect.hpp>
#include <imgproc.hpp>
#include <time.h>
using namespace cv;
using namespace std;


int detect_walker(Mat &image);
int detect_face(Mat image,const char *falter = "./data/haarcascades/haarcascade_frontalface_default.xml");
//int detect_face(Mat image,const char *falter = "./data/haarcascades/haarcascade_upperbody.xml");
void setCurrentVideoFileName(char *relust,int len);
int end_write_video(CvVideoWriter *writer);
int wirte_video(Mat &img,CvVideoWriter *writer);
CvVideoWriter* init_video_infomation(const char *filename,CvSize size,double fps);
#endif
