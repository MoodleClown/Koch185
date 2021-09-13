#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

//import matplotlib.pyplot as plt



using namespace cv;
using namespace std;
//C: / Users / Egor / source / repos / IzobrashenieConturi / IzobrashenieConturi / i.jpg

int main(int argc, char** argv) {
	//Mat cv::imread(const String & filename, int flags = IMREAD_UNCHANGED);
	Mat qwe = imread("i.jpg.jpg", 1);
	//IplImage* img = cvLoadImage("i.jpg");
	//Mat mat = Mat (img);
	//namedWindow("Display window", WINDOW_AUTOSIZE);
	

	
	/*Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);*/
	//putText(img, "OpenCV Step By Step", textOrg, fontFace, fontScale, color);

	//namedWindow("Hello world", 0);

	//imshow("Hello World", img);
	cv::imshow("Display window", qwe);
	waitKey(0);
	system("pause");
	return 0;
}