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
Mat img;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
		char filename[80];
		cout << "Ââåäèòå èìÿ ôàéëà, â êîòîðûé õîòèòå âíåñòè èçìåíåíèÿ, è íàæìèòå Enter" << endl;//
		cin.getline(filename, 80);
		cout << "Îòêðûòü ôàéë";
		cout << filename << endl;

		/*int height = 520;
		int width = 840;*/
		Mat img = imread(filename, 1);
		namedWindow("Èñõîäíîå èçîáðàæåíèå", WINDOW_AUTOSIZE);
		imshow("Èñõîäíîå èçîáðàæåíèå", img);
		
	Mat src_gray;
	Mat canny_output;
	cvtColor(img, src_gray, COLOR_RGB2GRAY);
	blur(src_gray, src_gray, Size(3, 3));

	/*double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout<<"Ïîðîãîâîå çíà÷åíèå" << otsu_thresh_val;*/
	double lower_thresh_val = 135;
	double high_thresh_val = lower_thresh_val * 1.65;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3);


	

	RNG rng(12345);
	vector < vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	
	vector<Moments> mu(contours.size());
	for (int i =0; i <contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	for (int i = 0; i < contours.size(); i++) {
		printf("Êîíòóð ¹ %d: öåíòð ìàññ - x = %.2à í =%.2f\n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true));
	}
	namedWindow("Ñåðîå èçîáðàæåíèå", WINDOW_AUTOSIZE);
	imshow("Ñåðîå èçîáðàæåíèå", canny_output);
	imwrite("canny_output.jpg", canny_output);
	
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	
	for (int i = 0; i < contours.size(); i++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 5, 0);
	}
	namedWindow("Êîíòóðû", WINDOW_AUTOSIZE);
	imshow("Êîíòóðû", drawing);

		waitKey(1);
		system("pause");
		return 0;
}
