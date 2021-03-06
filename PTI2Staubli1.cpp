#include "stdafx.h"
#include<iostream>
#include <fstream>  
#include<opencv2/opencv.hpp>


const int g_nMaxValue = 1;
int g_nValue;
IplImage *frame;
char *namecode[14] = { "1.jpg", "2.jpg", "3.jpg",
"4.jpg", "5.jpg", "6.jpg",
"7.jpg", "8.jpg", "9.jpg",
"11.jpg", "12.jpg", "13.jpg",
"14.jpg"
};
int i = 0;
void TakePhoto(int, void*)
{
	i++;
	cvSaveImage(namecode[i - 1], frame);
	if (i == 13)
	{
		i = 0;
	}

	std::cout << "拍照成功" << std::endl;
}

int main()
{
	cv::Mat image;

	g_nValue = 0;
	CvCapture *capture = cvCreateCameraCapture(0);
	cvNamedWindow("Camera");

	//创建一个滑块当按钮
	cv::createTrackbar("Photo", "Camera", &g_nValue, g_nMaxValue, TakePhoto);

	while (1)
	{

		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Camera", frame);

		char c = cvWaitKey(33);
		if (c == 27) break;
	}



	return 0;
}