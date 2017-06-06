#include <string>
#ifndef COURSE
#define COURSE
using namespace std;
class Course {
//There are generally three attributes
//the course code, the course name and the credit
private: 
	string _code;
	string _name;
	int _credit;

public:
//two constructors
	Course();
	Course(string code, string name, int credit);
	Course(const Course& course);
//three mutators
	void set_code(string code);
	void set_name(string name);
	void set_credit(int credit);
//three accessors 
	string get_code()const;
	string get_name()const;
	int get_credit()const;

//checking data input
	static bool check_code(string code);
	static bool check_name(string name);
	static bool check_credit(int credit);

//overload the oprators
	bool operator<(const Course& course)const;
	bool operator>(const Course& course)const;
	bool operator==(const Course& course)const;
	bool operator!=(const Course& course)const;



};


#endif
