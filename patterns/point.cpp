#include "point.h"

Point::Point(int a, int b):x(a),y(b), angle(0) {};

Point::~Point(){};

void Point::setPoint(int a, int b){
        x = a;
        y = b;
}

int Point::getX() const {
        return x;
}

int Point::getY() const{
        return y;
}


bool Point::operator<(const Point& other) const
 {
        if (angle<other.getAngle())return 1;
        else if ((angle == other.getAngle()) && y < other.getY())return 1;
        else if ((angle == other.getAngle()) && (y == other.getY()) && (x < other.getX())) return 1;
        return 0;

}


bool Point::operator==(const Point& other) const
{
        return (x == other.getX() && y == other.getY());
}

double Point::angleFromPoint(const Point& other) const
{
        return atan2((double)other.getY()-y, (double)other.getX()-x);
}

void Point::setAngle(double a){
        angle = a;
}

double Point::getAngle() const {return angle;};

