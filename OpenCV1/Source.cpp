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
		cout << "Введите имя файла, в который хотите внести изменения, и нажмите Enter" << endl;
		cin.getline(filename, 80);
		cout << "Открыть файл";
		cout << filename << endl;

		int height = 520;
		int width = 840;
		Mat img = imread(filename, 1);
		namedWindow("Исходное изображение", WINDOW_AUTOSIZE);
		imshow("Исходное изображение", img);
		
	/*Mat src_gray;
	cvtColor(qwe, src_gray, COLOR_RGB2GRAY);
	blur(src_gray, src_gray, Size(3, 3));
	double otsu_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3);

	char* source_grey_window = "Серое изображение";
	namedWindow(source_grey_window, WINDOW_AUTOSIZE);
	imshow(source_grey_window, canny_output);
	imwrite("canny_output.jpg", canny_output);*/

		waitKey(0);
		system("pause");
		return 0;
}