#include <string>
#include <cstdlib>
#include <iostream>
#ifndef COURSESELECTION
#define COURSESELECTION
using namespace std;
class CourseSelection{
private: 
//three attributes
	string _id;
	string _code;
	int _mark;

public:
//constructors
	CourseSelection();
	CourseSelection(string id, string code, int mark );
	CourseSelection(const CourseSelection& courseSelection);
//mutators 
	void set_id(const string& id);
	void set_code(const string& code);
	void set_mark(int mark);
//three accessor
	string get_id()const ;
	string get_code()const ;
	int get_mark()const;
	
	
	
//checker
	static bool check_id(string id);
	static bool check_code(string code);
	static bool check_mark(int mark);
//operator overload
	bool operator<(const CourseSelection& courseSelection)const;
	bool operator>(const CourseSelection& courseSelection)const;
	bool operator==(const CourseSelection& courseSelection)const;
	bool operator!=(const CourseSelection& courseSelection)const;
	friend ostream& operator<<(ostream& output, const CourseSelection& x){

	if(x.get_mark()==(-1)){
        	output<<"Student:"<<x.get_id()<<endl<<"Course:"<<x.get_code()<<endl<<"Mark: "<< "N/A"<<endl;
        	return output;
	}
	else{
        	output<<"Student:"<<x.get_id()<<endl<<"Course:"<<x.get_code()<<endl<<"Mark:"<< x.get_mark() <<endl;
        	return output;
	}
	};

};

#endif
