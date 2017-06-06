#include <string>
#include <list>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "courseSelection.h"
#include "student.h"
#include "course.h"
#ifndef SELECTION_TABLE
#define SELECTION_TABLE

//we need a comparing function for CourseSelection pointer
//because we need it for sorting
//later on I will implement it in courseSelection.h
using namespace std;
//This is a double linked list
//with two sets of indexes, which are implemented as hash tables
class SelectionTable {
//one default constructor
public:
	SelectionTable(int id_lists_size=29 , int code_lists_size=17 );

//accessors 
	
	bool contains(const string& id, const string& code)const;
	bool contains(const CourseSelection& x)const;

	bool contains_student(const string& id)const;
	bool contains_student(const Student& x)const;

	bool contains_course(const string& code)const;
	bool contains_course(const Course& x)const;

//This function return a const pointer to a entry in a table . we make it const because we want a better protection of the data inside
	const CourseSelection* find_selection(const string& id, const string& code)const;
//mutators
	bool insert(const CourseSelection& x);

	bool remove(const string& id);
	bool remove(const Student& x);

	bool remove(const string& id, const string& code);
	bool remove(const CourseSelection& x);
//This comparing function is compating the pointers using the value they are pointing to. This is more make sense when put then into a hush table
//we make it a class function to make it more clear and easy to use
	void save(string name);
	void print();
private: 
	int hash_id(const string& id)const;
	int hash_id(const CourseSelection& x)const;

	int hash_code(const string& code)const;
	int hash_code(const CourseSelection& x)const;
	

	
	list<CourseSelection> _data;
	vector<list<CourseSelection> >id_lists;
	vector<list<CourseSelection> >code_lists;
		
	int _id_lists_size;
	int _code_lists_size;
};




class Same_id_and_code {
private:
	string _id;
	string _code;
public:
	Same_id_and_code(const CourseSelection& x)
		:_id(x.get_id()),_code(x.get_code()){}

	Same_id_and_code(const string& id,const string& code)
		:_id(id),_code(code){}

	bool operator()(const CourseSelection& x) const {
		return( (_id==x.get_id()) && (_code==x.get_code()));
	}


};
// Okey I just cannot be bothered because i just dont want to move around these function objects so I make a new on instead of overloading it
class Same_id_selection {
private: 
	string _id;
public: 
	Same_id_selection(string id):_id(id){}
	bool operator()(const CourseSelection& x)const{
		return _id==x.get_id();
	}
};

class Same_code_selection {
private: 
	string _code;
public:
	Same_code_selection(string code):_code(code){}
	bool operator()(const CourseSelection x)const{
		return _code==x.get_code();
	}

};


#endif
