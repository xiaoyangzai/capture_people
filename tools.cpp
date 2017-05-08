#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <time.h>
#include "tools.h"
using namespace cv;
using namespace std;


void setCurrentVideoFileName(char *result,int len)
{
	time_t rawtime;
	struct tm* timeinfo;	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	memset(result,0,len);
	sprintf(result,"./video/%d-%.2d-%.2d-%.2d-%.2d-%.2d.avi",1900+timeinfo->tm_year,timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
	return ;
}
CvVideoWriter* init_video_infomation(const char *filename,CvSize size,double fps)
{
	CvVideoWriter *writer = cvCreateVideoWriter(filename,CV_FOURCC('M', 'J', 'P', 'G'),fps,size); //创建视频文件  
	if(writer == NULL) 
		cout<<"create video writer failed\n"		;
	return writer;
}
int wirte_video(Mat &img,CvVideoWriter *writer)
{
	IplImage pimg(img);
	cvWriteFrame(writer,&pimg); //保存图片为视频流格式  
	return 0;
}
int end_write_video(CvVideoWriter *writer)
{
	cvReleaseVideoWriter(&writer);
	return 0;
}


int detect_face(Mat image,const char *falter)
{
	if(!image.data || !falter)
	{
		printf( "No image data \n" );
		return -1;
	}

	CascadeClassifier face_haar(falter);
	if(face_haar.empty() == true)
	{
		cout<<"load xml failed\n";
		return -1;
	}

	vector <Rect> faces;
	face_haar.detectMultiScale(image,faces);
	//cout<<"face count: "<<faces.size()<<endl;
	for(int i = 0;i < faces.size();i++)
	{
		rectangle(image,Point(faces[i].x,faces[i].y),Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),Scalar(0,255,0),2);
	}

	return faces.size();
}
int detect_walker(Mat &image)
{
	if(!image.data)
	{
		printf( "No image data \n" );
		return -1;
	}
	vector <Rect> found,foundRect;
	HOGDescriptor defaultHog;
	defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector()); 
	defaultHog.detectMultiScale(image, found);


	//ignore the overlap detection
	for(int i = 0; i < found.size(); i++)
	{
		Rect r = found[i];
		int j = 0;
		for(; j < found.size(); j++)
		{
			if( j != i && (r & found[j]) == r)
				break;
		}
		if(j == found.size())
		{
			foundRect.push_back(r);
		}
	}
	
	//cout<<"face count: "<<foundRect.size()<<endl;
	for(int i = 0;i < foundRect.size();i++)
	{
		Rect r = foundRect[i];
		rectangle(image,r.tl(),r.br(),Scalar(0,0,255),2);
	}

	return foundRect.size();
}

//int main( int argc, char** argv )
//{
//	if( argc != 3)
//	{
//		printf( "need three arguments for this application\n" );
//		return -1;
//	}
	//char * videoname = setCurrentVideoFileName();
	//cout<<"video will save into the file "<<videoname<<endl;
	//CvSize size = cvSize(360,240);  //视频帧格式的大小
	//double fps = 2; 
	//CvVideoWriter* writer = init_video_infomation(videoname,size,fps);

	//char cname[100];  
	////加载图片的文件夹，图片的名称编号是1开始1，2,3,4,5.。。。  
	//sprintf(cname,"./movie/%d.jpg",0); 
	//int count = 0;
	//int num = 0;
	//while(count < 10)
	//{
	//	IplImage *src = cvLoadImage(cname);  
	//	
	//	if (!src)  
	//	{
	//		cout<<"load image failed\n";
	//		return -1;  
	//	}
	//	wirte_video(src,writer,size);
	//	num++;  
	//	if(num >= 5)
	//		num = num%5;
	//	memset(cname,0,sizeof(cname));
	//	sprintf(cname,"./movie/%d.jpg",num);  
	//	count++;
	//}
	//end_write_video(writer);
	//cout<<"video is saved completly!!\n";
//	Mat image;
//	image = imread(argv[1],0);
//	//detect_face(image,argv[2]);
//	detect_walker(image);
//	return 0;
//}
