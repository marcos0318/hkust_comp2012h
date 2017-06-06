#include "student.h"
Student::Student()
	:_id(""),_name(""),_year(-1),_gender("")
{}
//constructors
Student::Student(string id, string name, int year, string gender)
	:_id(id),_name(name),_year(year),_gender(gender){}

Student::Student(const Student& student)
	:_id(student._id),_name(student._name),_year(student._year),_gender(student._gender){}
//mutators
void Student::set_name(string name){
	_name = name;
}

void Student::set_id(string id){
	_id = id;
}

void Student::set_year(int year){
	_year = year;
}

void Student::set_gender(string gender){
	_gender = gender;
}
//accessors
string Student::get_name() const{
	return _name;
}

string Student::get_id() const{
	return _id;
}

string Student::get_gender() const {
	return _gender;
}
int Student::get_year() const {
	return _year;
}

//checkers
bool Student::check_id(string id){
//The length of the string have to be 8
	if (id.length()!=8) return false;
//numeric checking employing the cstdlib
	char *p;
	strtol(id.c_str(), &p , 10);
	return (*p == 0);
}

bool Student::check_name(string name){
//The length is between 1 and 32, included
	if (name.length()>=1&&name.length()<=32)return true;
	return false;
}

bool Student::check_gender(string gender){
//either m or f
	if (gender=="m"||gender=="M"||gender=="f"||gender=="F"){
		return true;
	}
	return false;
}

bool Student::check_year(int year){
//from 1 to 3
	if (year>=1&&year<=3){
		return true;
	}
	return false;
}

//overloading operators

bool Student::operator<(const Student& student )const {
	return( _id < student._id);
}


bool Student::operator>(const Student& student)const {
	return( _id > student._id);
}


bool Student::operator==(const Student& student)const {
	return( _id == student._id);
}


bool Student::operator!=(const Student& student)const {
	return( _id != student._id);
}












