#include <string>
#include <cstdlib>
#ifndef STUDENT
#define STUDENT
using namespace std;
class Student{

private:
//One Student have four attributes
//the Student name
//the Student ID 
//the year of study 
//and the gender
//we consider only have the default construct and copy constructor

	string _id;
	string _name;
	int _year;
	string _gender;
public:
	Student();
//the constructor that take four attributes together
	Student( string id, string name, int year, string _gender );
//the copy constructor
	Student(const Student& student);
//four mutators
	void set_name(string name);
	void set_id(string id);
	void set_year(int year);
	void set_gender(string gender);
//four accessors	
	string get_name() const;
	string get_id() const;
	int get_year() const;
	string get_gender()const;

//four static funcitons to check the validity of the data intake
	static bool check_id(string id);
	static bool check_name(string name);
	static bool check_gender(string gender);
	static bool check_year(int year);

//overload operators used in comparing;
	bool operator<(const Student& student )const;
	bool operator==(const Student& student )const;
	bool operator>(const Student& student)const;
	bool operator!=(const Student& student)const;





};



#endif
