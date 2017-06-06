#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "course.h"
#ifndef COURSE_TABLE
#define COURSE_TABLE
using namespace std;
//This is also a separate lists hash table
//Did not implement a generic hash table
//Because the code is similar, more comments in in the studentTable.h
//The data are stored in lists held together by a vector
class CourseTable {
public:
	CourseTable(int size = 17);

	bool contains(const string& code)const;
        bool contains(const Course& x)const;

	void makeEmpty();
        bool insert(const Course& x);
        bool remove(const string& code);

	const Course* find_course(const string& code)const;
        void print();
	void save(string name);
private:
	vector<list<Course> > theLists;
	int _size;

	int myhash(const string& code)const;
	int myhash(const Course& x)const;

};

class Same_code{
private:
	string _code;
public:
	Same_code(string code):_code(code){}
	bool operator()(const Course& x)const{
		return _code==x.get_code();
	}
};
#endif
