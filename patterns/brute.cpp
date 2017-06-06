#include "brute.h"
Brute::Brute(std::vector<Point> vec)
	:points(vec)
{
	int m = 0;
	int n = 0;
	std::vector<Point> tmp;
	for(int p = 0; p < points.size(); p++)
	for(int q = p+1; q < points.size(); q++)
	for(int r = q+1; r < points.size(); r++)
	for(int s = r+1; s < points.size(); s++){
		m = (points[q].y -points[p].y)
			*(points[r].x -points[p].x )
			-(points[q].x - points[p].x)
			*(points[r].y - points[p].y);
		n = (points[q].y -points[s].y)
			*(points[r].x -points[s].x )
			-(points[q].x - points[s].x)
			*(points[r].y - points[s].y);
		if (n == 0 && m == 0){
			tmp.push_back(points[p]);
			tmp.push_back(points[q]);
			tmp.push_back(points[s]);
			tmp.push_back(points[r]);
			lines.push_back(tmp);
			tmp.clear();
		}

	
	}   
	
}

