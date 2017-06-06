#include "courseSelection.h"
CourseSelection::CourseSelection():_id(""),_code(""),_mark(-1)
{}


CourseSelection::CourseSelection(string id, string code, int mark)
	:_id(id),_code(code),_mark(mark)
{}

CourseSelection::CourseSelection(const CourseSelection& x)
	:_id(x._id), _code(x._code),_mark(x._mark)
{}

void CourseSelection::set_mark(int mark){
	_mark = mark;
}

void CourseSelection::set_id(const string& id){
	_id = id;
}

void CourseSelection::set_code(const string& code){
	_code = code;
}

string CourseSelection::get_id()const{
	return _id;
}

string CourseSelection::get_code()const{
	return _code;
}

int CourseSelection::get_mark()const{
	return _mark;
}

bool CourseSelection::check_code(string code){
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

bool CourseSelection::check_id(string id){
	if (id.length()!=8) return false;
	char *p;
	strtol(id.c_str(), &p , 10);
	return (*p == 0);
}

bool CourseSelection::check_mark(int mark){
	if (mark>=0&&mark<=100)return true;
	return false;	
}

bool CourseSelection::operator<(const CourseSelection& courseSelection)const{
	if(_id < courseSelection._id)return true;
	else if ((_id == courseSelection._id) && (_code<courseSelection._code))return true;
	else return false;
}

bool CourseSelection::operator>(const CourseSelection& courseSelection)const{
	if(_id > courseSelection._id )return true;
	else if ((_id == courseSelection._id) && (_code>courseSelection._code))return true;
	else return false;
}

bool CourseSelection::operator==(const CourseSelection& courseSelection)const{
	if((_id == courseSelection._id) && (_code == courseSelection._code))return true;
	else return false;
}

bool CourseSelection::operator!=(const CourseSelection& courseSelection)const{
	return ((_id != courseSelection._id) ||( _code != courseSelection._code));
}


