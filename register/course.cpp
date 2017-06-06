#include "course.h"
//two constructors

Course::Course():_code(""),_name(""),_credit(-1)
{}

Course::Course(string code,string name,int credit)
	:_code(code),_name(name),_credit(credit)
{
}

Course::Course(const Course& course)
	:_code(course._code),_name(course._name),_credit(course._credit)
{}

//three mutators
void Course::set_code(string code){
	_code = code;
}
void Course::set_name(string name){
	_name = name;
}

void Course::set_credit(int credit){
	_credit = credit;
}

//three accessors

string Course::get_code()const {
	return _code;
}

string Course::get_name()const{
	return _name;
} 

int Course::get_credit()const {
	return _credit;
}

//checkers of the data input

bool Course::check_code(string code){
	if (code.length()!=7&&code.length()!=8){
		return false;
	}
	for (int i = 0; i<4; i++){
		if(code[i]<'A'||code[i]>'Z'){
			return false;
		}
	}
	for (int i =4; i< code.length();i++){
		if(!( code[i]>='A' && code[i]<='Z' || code[i]>='0'&&code[i]<='9'  ))
		return false;
	}
	return true;
}


bool Course::check_name(string name){
	if (name.length()>= 1&& name.length()<=50){return true;}
	return false;	

}

bool Course::check_credit(int credit){
	if (credit>=0&&credit<=5){return true;}
	return false;
}

//operators
bool Course::operator<(const Course& course)const{
	return (_code < course._code );
}

bool Course::operator>(const Course& course)const{
	return (_code > course._code);
}

bool Course::operator==(const Course& course)const{
	return (_code.compare(course._code)==0);
}
bool Course::operator != (const Course& course)const{
	return (_code.compare(course._code)!=0);
}



















