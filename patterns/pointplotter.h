#include "fast.h"
#include "brute.h"
#include "point.h"
#include <cstdio>
#include <iostream>
#include <QPainter>
#include <QtGui>
#include <vector>
#include <fstream>
#include <algorithm>
#ifndef POINTPLOTTER
#define POINTPLOTTER
class PointPlotter :public QWidget{
	Q_OBJECT
public: 
	PointPlotter(char * path);
	void paintPoint(Point p);
	void paintLine(Point, Point);
	static bool presort(const Point &a, const Point &b ){
		if (a.y<b.y)return 1;
		else if (a.y == b.y && a.x < b.x)return 1;
		else return 0;
	}
private:
//Gui things
	QPushButton *fastButton;
	QPushButton *bruteButton;
	QLabel background;	
	QLabel runtime;
	QImage img;
	QVBoxLayout layout;	
	
//Data stored
	std::vector<Point> points;
	int number;
	char time[256];

	Fast *fastlines;
	Brute *brutelines;

public slots:
	void useFast();
	void useBrute();	

		
};

#endif
