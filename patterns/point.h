#ifndef POINT
#define POINT
#include<cmath>
class Point{
friend class Brute;
friend class PointPlotter;
public:
	Point(int a, int b);
	~Point();
	void setPoint(int a, int b);
	int getX() const;
	double getAngle() const;
	int getY() const;
	double angleFromPoint(const Point& other) const;
	bool operator< (const Point& other) const ;
	bool operator==(const Point& other) const ;
	void setAngle(double a);
	
private:
	int x;
	int y;	
	double angle;

};
#endif


