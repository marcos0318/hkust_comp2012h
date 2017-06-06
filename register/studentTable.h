#include <string>
#include <cmath>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "student.h"
#ifndef STUDENT_TABLE
#define STUDENT_TABLE
using namespace std;
//This is a separate lists hash table
//The data are stored in lists held together by a vector
class StudentTable {
public:
//one convertion constructor
	StudentTable (int size = 29 );
//acceesor

	bool contains(const string& id)const;
	bool contains(const Student& student)const;
	const Student* find_student(const string& id)const;
//mutators

	void makeEmpty();
	bool insert(const Student& student);
	bool remove(const string& id);
	
	void print();
	void save(string name);

private:
	vector<list<Student> > theLists;//The array of the lists
	int _size;


//private methods
	
	int myhash(const string& id)const;
	int myhash(const Student& x)const;
};


//function object to be used in find
class Same_id{
private:
	string _id;
public:
	Same_id(string id):_id(id){}
	bool operator()(const Student& student )const{
		return _id==student.get_id();
	}
};
#endif
