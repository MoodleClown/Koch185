#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream> //Объявляет объекты, управляющие чтением из стандартных потоков и записью в них.
#include<stdio.h>//STanDard Input/Output Header-- использовалось для ввода вывода файлов
#include<stdlib.h>

using namespace cv; //using Директива позволяет использовать все имена в namespace для использования без имени пространства имен в качестве явного квалификатора. Использование директивы using в файле реализации
using namespace std;

int main(int argc, char** argv) {
	int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);//создаем матрицу 

	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;//позволяет определить настройки шрифтов
	double fontScale = 2; //отвечает за ширину шрифта 
	Scalar color(200, 100, 50);//цвет изображения
	putText(img, "OpenCV Step By Step", textOrg, fontFace, fontScale, color);//вставляет текст с нужными настройками

	imshow("Hello World", img);//отвечает за вывод изображения
	
	waitKey(0);//нужна для обработки изображения
	system("pause");//нужно для того, чтобы окно сразу не закрывалось.
	return 0;




}
