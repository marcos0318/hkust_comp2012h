#include <iostream>
#include "course.h"
#include "student.h"
#include "courseSelection.h"
#include "selectionTable.h"
#include "studentTable.h"
#include "courseTable.h"
using namespace std;


StudentTable students = StudentTable();
CourseTable courses = CourseTable();
SelectionTable selections = SelectionTable();

string StudentIDInput(){
	cout << "Enter student ID: "<<endl;
	string str;
	getline(cin,str);
	while (!Student::check_id(str)){
		cout<<"Invalid ID, please enter again [student ID]:"<<endl;
		getline(cin,str);
	}
	return str;
}
string StudentNameInput(){
	cout << "Enter student name: "<<endl;
	string str;
	getline(cin,str);
	while (!Student::check_name(str)){
		cout<<"Invalid name, please enter again [student ID]:"<<endl;
		getline(cin,str);
	}
	return str;
	
}
int StudentYearInput(){
	cout << "Enter year[1-3]: "<<endl;
	string str;
	getline(cin,str);
	int i = atoi(str.c_str());
	while (!Student::check_year(i)){
		cout<<"Invalid year, please enter again [1-3]:"<<endl;
		getline(cin,str);
		i = atoi(str.c_str());
	}
	return i;
	
}

string StudentGenderInput(){
	cout <<"Enter gender [M/F]: "<<endl;
	string str;
	getline(cin, str);
	while(!Student::check_gender(str)){
		cout<<"Invalid gender, please enter again [M/F]: "<<endl;
		getline(cin,str);
	}
	if (str=="f"){return "F";}
	else if (str == "m"){return "M";}
	else return str;
}

string CourseCodeInput(){
	cout<<"Enter course code: "<<endl;
	string str;
	getline(cin,str);
	while(! Course::check_code(str)){
		cout<<"Invalid course code, please enter again: "<<endl;
		getline(cin,str);	
	}
	return str;

}

string CourseNameInput(){
	cout<<"Enter course name: "<<endl;
	string str;
	getline(cin ,str);
	while(!Course::check_name(str)){
		cout<<"Invalid name, please enter again: "<<endl;
		getline(cin,str);
	}
	return str;
}

int CourseCreditInput(){
	cout<<"Enter course credit: "<<endl;
	string str;
	int i;
	getline(cin,str);
	i = atoi(str.c_str());
	while (!Course::check_credit(i)){
		cout<<"Invalid credit, please enter again: [0-5] "<<endl;
		getline(cin,str);
		i = atoi(str.c_str());
	}
	return i;
	
}

int SelectionMarkInput(){
	cout<<"Enter exam mark: "<<endl;
	string str;
	int i;
	getline(cin, str);
	i = atoi(str.c_str());
	while (!CourseSelection::check_mark(i)){
		cout<<"Invalid mark, please enter again: [0-100]"<<endl;
		getline(cin,str);
		i = atoi(str.c_str());
	}
	return i;

}

void endOfLoop(){
	string str;
	cout << "...Hit ENTER to continue..."<<endl;
	getline(cin, str);
	system("clear");
}


void CourseRegistration(){
	
        int current_option;
        string option_str;
        system("clear");

        cout<<"HKUST Course Registration System (Registration Menu)"<<endl;
        cout<<"------------------------------------------------"<<endl<<endl;
	cout<<"1. Add course"<<endl;
	cout<<"2. Drop course"<<endl;
	cout<<"3. Modify Exam Mark"<<endl;
	cout<<"4. Query registration"<<endl;
	cout<<"5. Go back to main menu"<<endl;

        getline(cin, option_str);
        current_option = atoi(option_str.c_str());
        while(current_option > 5 || current_option < 1) {
                cout<<"Invalid input, re-enter again (1-5): ";
                getline(cin, option_str);
                current_option = atoi(option_str.c_str());
        }
	
	if (current_option == 1){
		//add a course
		CourseSelection selection;
		//id input
		string id = StudentIDInput();
		//Check the if there is a student with the id
		if (!students.contains(id)){
			cout<<"Error: the student does not exist"<<endl;
		endOfLoop();
		return;
		}
		//code input 
		string code = CourseCodeInput();
		//check if there is a course with the code
		if(!courses.contains(code)){
			cout<<"Error: the course does not exist"<<endl;
		endOfLoop();
		return;
		}


		selection.set_id(id);
		selection.set_code(code);

		//check if the selection has existed
		if (selections.contains(id, code)){
			cout<<"The student has registered this course"<<endl;
		endOfLoop();
		return;
		}
		//ok, we are going to add this course
		
		if(selections.insert(selection)){
			cout<<"The course is added!"<<endl;
			endOfLoop();
			return;
		}
		else {
			cout<<"Error: unsuceessful adding"<<endl;
			endOfLoop();
			return;
		}
		
	}
	else if (current_option == 2){
		//delete a course
                CourseSelection selection;
                //id input
                string id = StudentIDInput();
                //Check the if there is a student with the id
                if (!students.contains(id)){
                        cout<<"Error: the student does not exist"<<endl;
                endOfLoop();
                return;
                }
                //code input 
                string code = CourseCodeInput();
                //check if there is a course with the code
                if(!courses.contains(code)){
                        cout<<"Error: the course does not exist"<<endl;
                endOfLoop();
                return;
                }
                //check if the selection has existed
		
                if (!selections.contains(id, code)){
                        cout<<"The student did not register this course"<<endl;
                endOfLoop();
                return;
                }
		

		//to delete this course
		if (selections.remove(id,code)){
			cout<<"Remove success!"<<endl;
			endOfLoop();
			return;
		}
		else {
			cout<<"unsuccessful removal"<<endl;
			endOfLoop();
			return;
		}
		
	}
	else if (current_option == 3){
		//Modify a mark
                CourseSelection selection;
                //id input
                string id = StudentIDInput();
                //Check the if there is a student with the id
                if (!students.contains(id)){
                        cout<<"Error: the student does not exist"<<endl;
                endOfLoop();
                return;
                }
                //code input 
                string code = CourseCodeInput();
                //check if there is a course with the code
                if(!courses.contains(code)){
                        cout<<"Error: the course does not exist"<<endl;
                endOfLoop();
                return;
                }
                //check if the selection has existed
                if (!selections.contains(id,code)){
                        cout<<"The student did not register this course"<<endl;
                endOfLoop();
                return;
                }
		
		int mark = SelectionMarkInput();
		
		selection.set_id(id);
		selection.set_code(code);
		selection.set_mark(mark);

		if(selections.remove(id,code)&&selections.insert(selection)){
			cout<<"Course added"<<endl;
			endOfLoop();
			return;
		}else{
			cout <<"Unsuccess"<<endl;
			endOfLoop();
			return;
		
		}

	}
	else if (current_option == 4){
		//query a record
		const CourseSelection* p;

		                //id input
                string id = StudentIDInput();
                //Check the if there is a student with the id
                if (!students.contains(id)){
                        cout<<"Error: the student does not exist"<<endl;
                endOfLoop();
                return;
                }
                //code input 
                string code = CourseCodeInput();
                //check if there is a course with the code
                if(!courses.contains(code)){
                        cout<<"Error: the course does not exist"<<endl;
                endOfLoop();
                return;
                }
                //check if the selection has existed
                if (!selections.contains(id,code)){
                        cout<<"The student did not register this course"<<endl;
                endOfLoop();
                return;
                }

		p = selections.find_selection(id,code);
		if (p == 0){cout << "this is the problem"<<endl;
		endOfLoop();
		return;}	
		cout<<*p<<endl;
		endOfLoop();
		return ;
	}

	else if (current_option == 5){
		return;
	}

	
}

void StudentManagement() {
        int current_option;
        string option_str;
        system("clear");

        cout<<"HKUST Course Registration System (Student Menu)"<<endl;
        cout<<"------------------------------------------------"<<endl<<endl;
        cout<<"1. Insert Student Record"<<endl;
        cout<<"2. Modify Student Record"<<endl;
        cout<<"3. Delete Student Record"<<endl;
        cout<<"4. Query Student Record"<<endl;
        cout<<"5. Go back to main menu"<<endl<<endl;
        cout<<"Enter your choice (1-5): ";


        getline(cin, option_str);
        current_option = atoi(option_str.c_str());
        while(current_option > 5 || current_option < 1) {
                cout<<"Invalid input, re-enter again (1-5): ";
                getline(cin, option_str);
                current_option = atoi(option_str.c_str());
        }

        if(current_option == 1) {
                Student stu;
                string id;

                id = StudentIDInput();
                if(students.contains(id)) {
                        cout<<"Error: The Student has already existed"<<endl<<endl;
                        endOfLoop();
                        return;
                }
		stu.set_id(id);
		
    		stu.set_name(StudentNameInput());

    		stu.set_year(StudentYearInput());

    		stu.set_gender(StudentGenderInput());

    		if(students.insert(stu)){
      			cout<<"Creation of student record successful"<<endl<<endl;
    		}else {
      			cout<<"Error: Creation of student record fail"<<endl<<endl;
    		}

    		endOfLoop();

		
		
    	}	

	else if(current_option == 2){
		Student student;
		string id = StudentIDInput();
		if(!students.contains(id)){
			cout<<"Error: Student not exist!"<<endl;
		}	
		else {
			student.set_id(id);
			
			student.set_name(StudentNameInput());

			student.set_year(StudentYearInput());
			
			student.set_gender(StudentGenderInput());

			if(students.remove(id)&& students.insert(student)){
				cout<<"Modify student record complete"<<endl;
			}
			else{cout << "Unable to modify the record"<<endl;}
		}
		endOfLoop();
	
	}

	else if(current_option == 3){
		string id = StudentIDInput();
		if(!students.contains(id)){
			cout<<"Error: Student not exist!"<<endl;
		}
		else {
			if (students.remove(id)){
				selections.remove(id);
				cout<<"Remove success!"<<endl;
			}
		}
		endOfLoop();
	}
	
	else if(current_option == 4){
		string id = StudentIDInput();
		if(!students.contains(id)){
			cout<<"Error: Student not exist!" <<endl;
			endOfLoop();
			return;
		}
		const Student* stu = students.find_student(id);
		cout << "Name:" << stu->get_name()<<endl;
		cout << "Student ID: "<<stu->get_id()<<endl;
		cout << "Year: "<< stu->get_year()<<endl;
		cout << "Gender: "<< stu->get_gender()<<endl;
		
		endOfLoop();
		return;
	}
	

	
	else if (current_option ==5){
		return;
	}

	

}

void CourseManagement(){
        int current_option;
        string option_str;
        system("clear");

        cout<<"HKUST Course Registration System (Course Menu)"<<endl;
        cout<<"------------------------------------------------"<<endl<<endl;
        cout<<"1. Insert Course Record"<<endl;
        cout<<"2. Modify Course Record"<<endl;
        cout<<"3. Delete Course Record"<<endl;
        cout<<"4. Query Course Record"<<endl;
        cout<<"5. Go back to main menu"<<endl<<endl;
        cout<<"Enter your choice (1-5): ";

        getline(cin, option_str);
        current_option = atoi(option_str.c_str());
        while(current_option > 5 || current_option < 1) {
                cout<<"Invalid input, re-enter again (1-5): ";
                getline(cin, option_str);
                current_option = atoi(option_str.c_str());
        }
	
	
        if(current_option == 1) {
                Course course;
                string code;

                code = CourseCodeInput();
                if(courses.contains(code)) {
                        cout<<"Error: The course has already existed"<<endl<<endl;
                        endOfLoop();
                        return;
                }
                course.set_code(code);

                course.set_name(CourseNameInput());

                course.set_credit(CourseCreditInput());

                if(courses.insert(course)){
                        cout<<"Creation of course record successful"<<endl<<endl;
                }else {
                        cout<<"Error: Creation of course record fail"<<endl<<endl;
                }

                endOfLoop();



        }
        else if(current_option == 2) {
                Course course;
                string code;

                code = CourseCodeInput();
                if(!courses.contains(code)) {
                        cout<<"Error: The course does not existed"<<endl<<endl;
                        endOfLoop();
                        return;
                }

                course.set_code(code);
                course.set_name(CourseNameInput());

                course.set_credit(CourseCreditInput());

                if(courses.remove(code)&&courses.insert(course)){
                        cout<<"Modification of course record successful"<<endl<<endl;
                }else {
                        cout<<"Error: Modification of course record fail"<<endl<<endl;
                }

                endOfLoop();



        }
	else if(current_option == 3){
		string code;
                code = CourseCodeInput();
                if(!courses.contains(code)) {
                        cout<<"Error: The course does not existed"<<endl<<endl;
                        endOfLoop();
                        return;
                }
		
		else {	


			
			if (selections.contains_course(code)){
			cout<<"Some students are taking this course, you cannot remove it"<<endl;
			endOfLoop();
			return;
			}


			if (courses.remove(code)){
				cout<<"Remove success!"<<endl;
			}
		}
		
                endOfLoop();
		
	
	}

	
	else if(current_option == 4){
		string code = CourseCodeInput();
		if(!courses.contains(code)){
			cout<<"Error: Course does not exist!" <<endl;
			endOfLoop();
			return;
		}
		const Course* p = courses.find_course(code);
		cout << "Code: " << p->get_code()<<endl;
		cout << "Course Name: "<<p->get_name()<<endl;
		cout << "Credit: "<< p->get_credit()<<endl;
		
		endOfLoop();
	}
	

	
	else if (current_option ==5){
		return;
	}
	
	
	




}

void FileManagement(){
	int current_option;
	string option_str;
	system("clear");
	
        cout<<"HKUST Course Registration System (File Menu)"<<endl;
        cout<<"------------------------------------------------"<<endl<<endl;
        cout<<"1. Save Database"<<endl;
        cout<<"2. Load Database"<<endl;
        cout<<"3. Go back to main menu"<<endl;

        getline(cin, option_str);
        current_option = atoi(option_str.c_str());
        while(current_option > 3 || current_option < 1) {
                cout<<"Invalid input, enter again (1-3): ";
                getline(cin, option_str);
                current_option = atoi(option_str.c_str());
        }
	
	if (current_option == 1){
		string name;
		cout << "Enter the file name:"<<endl;
		getline(cin, name);
		students.save(name);
		courses.save(name);
		selections.save(name);
		endOfLoop();
		return ;
		

	}
	else if (current_option ==2){
		string name;
		cout << "Enter the file name:"<<endl;
		getline(cin,name);
		ifstream fin(name.c_str());
		string line;
		getline(fin, line);
		if (!(line=="database")){
			cout<<"not a database"<<endl;
			endOfLoop();
			return;
		}
		while (getline(fin, line)){
			if (line == "student"){
				Student stu;
				getline(fin, line);
				stu.set_id(line);

				getline(fin, line);
				stu.set_name(line);
				
				getline(fin ,line);
				int i = atoi(line.c_str());
				stu.set_year(i);
				
				getline(fin,line);
				stu.set_gender(line);
					
				students.insert(stu);
				
			}
			else if(line == "course"){
				Course course;
				
				getline(fin, line);
				course.set_code(line);
				
				getline(fin, line);
				course.set_name(line);
	
				getline(fin, line);
				int i = atoi(line.c_str());
				course.set_credit(i);
				
				courses.insert(course);
			}
			else if (line == "selection"){
				CourseSelection selection;
				
				getline(fin,line);
				selection.set_id(line);
				
				getline(fin,line);
				selection.set_code(line);
				
				getline(fin,line);
				int i =atoi( line.c_str());
				selection.set_mark(i);

				selections.insert(selection);
			}	
			else {cout<<"bad database"<<endl;endOfLoop();return;}
			

		}	
		endOfLoop();
	}

	else if (current_option ==3){
		return;
	}


	

}


void main_loop(){
        int option;
        string option_str;
        system("clear");

        cout<<"HKUST Course Registration System"<<endl;
        cout<<"--------------------------------"<<endl<<endl;
        cout<<"1. Student Management"<<endl;
        cout<<"2. Course Management"<<endl;
        cout<<"3. Course Registration"<<endl;
        cout<<"4. Report Management(not implemented)"<<endl;
        cout<<"5. File Management"<<endl;
        cout<<"6. Exit" <<endl<<endl;
        cout<<"Enter your choice (1-6): ";


        getline(cin, option_str);
        option = atoi(option_str.c_str());
        while(option > 6 || option < 1) {
                cout<<"Invalid input, re-enter again (1-6): ";
                getline(cin, option_str);
                option = atoi(option_str.c_str());
        }
        if(option == 1) {
                StudentManagement();
        }else if(option == 2) {
                CourseManagement();
        }else if(option == 3) {
                CourseRegistration();
        }else if(option == 4) {
               // ReportManagement();
        }else if(option == 5) {
                FileManagement();
        }else if(option == 6) {
                exit(0);
        }
        return;
}




int main(){
	while (true){
		main_loop();
	}
	

}

