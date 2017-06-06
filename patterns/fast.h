#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "point.h"
#ifndef FAST
#define FAST

class Fast {
friend class PointPlotter;
public:	
	Fast(std::vector<Point> vec );
	bool IsIncluded(std::vector<Point> tmp);
	double runtime;
private:
	std::vector<Point> points;
	std::vector<Point> copy;
	std::vector<std::vector<Point> > lines;
};



#endif
