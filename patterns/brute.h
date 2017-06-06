#include <iostream>
#include <algorithm>
#include <vector>
#include "point.h"
#ifndef BRUTE
#define BRUTE

class Brute {
friend class PointPlotter;
public:
	Brute(std::vector<Point> vec  );
	bool IsIncluded(std::vector<Point> tmp);
	double runtime;
private:
	std::vector<Point> points;
	std::vector<Point> copy;
	std::vector<std::vector<Point> > lines;

};
#endif
