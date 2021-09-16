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
	setlocale(LC_ALL, "Russian");//задает локаль, которая будет использоваться текущей программой.
		char filename[80];
		cout << "Введите имя файла, в который хотите внести изменения, и нажмите Enter" << endl;//стандартный выходной поток. Здесь мы выводим надпись в консоль
		cin.getline(filename, 80);//предназначена для ввода данных из потока
		cout << "Открыть файл";//выводим надпись
		cout << filename << endl;// endl означает что значение начнется со следующей строки

		/*int height = 520;
		int width = 840;*/
		Mat img = imread(filename, 1);
		namedWindow("Исходное изображение", WINDOW_AUTOSIZE);
		imshow("Исходное изображение", img);
		
	Mat src_gray;
	Mat canny_output;
	cvtColor(img, src_gray, COLOR_RGB2GRAY);//преобразует цветовое пространство матрицы
	blur(src_gray, src_gray, Size(3, 3));//размытие 

	/*double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout<<"Пороговое значение" << otsu_thresh_val;*/
	double lower_thresh_val = 135;//нижняя граница
	double high_thresh_val = lower_thresh_val * 1.65;//врхняя граница
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3);//Canny - детектор границ, а строчкой мы задаем ему "чувствительность", а точнее верхние и нижние границы


	namedWindow("Серое изображение", WINDOW_AUTOSIZE);
	imshow("Серое изображение", canny_output);
	imwrite("canny_output.jpg", canny_output);//записывает индексированное изображение, находящееся в массиве X, и соответствующую ему цветовую палитру тар в файл filename

		waitKey(0);
		system("pause");
		return 0;
}
