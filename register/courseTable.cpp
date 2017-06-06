#include "courseTable.h"
CourseTable::CourseTable(int size)
	:_size(size)
{
	vector<list<Course> > * vp =new vector<list<Course> >(_size);
	theLists = *vp;
}

//check whether a course in the table with course_code
bool CourseTable::contains(const string& code)const{
	const list<Course>& whichList = theLists[myhash(code)];
	list<Course>::const_iterator itr = find_if(whichList.begin(),whichList.end(), Same_code(code));
	if(itr != whichList.end())return true;
	else return false;
}

const Course* CourseTable::find_course(const string& code)const{
	const list<Course>& whichList = theLists[myhash(code)];
	list<Course>::const_iterator itr = find_if(whichList.begin(),whichList.end(), Same_code(code));
	if(itr != whichList.end())return &(*itr);
	else return 0;
}



//check whether a course in the table with course
bool CourseTable::contains(const Course& x)const {
	return contains(x.get_code());
}

//clear all the records
void CourseTable::makeEmpty(){
	for (size_t i =0; i< theLists.size();i++){
		theLists[i].clear();
	}
}

//insert a course
bool CourseTable::insert(const Course& x){
	list<Course>& whichList = theLists[myhash(x)];
	list<Course>::iterator itr = find(whichList.begin(),whichList.end(),x);
	if (itr != whichList.end())return false;
	whichList.push_back(x);
	whichList.sort();
	return true;
}

//remove a course with code
bool CourseTable::remove(const string& code){
	list<Course>& whichList = theLists[myhash(code)];
	list<Course>::iterator itr = find_if(whichList.begin(), whichList.end(),Same_code(code));
	if (itr == whichList.end())return false;
	whichList.erase(itr);
	return true;
}

//the hash function
int CourseTable::myhash(const string& code)const{
	int value = 0;
	for (unsigned i = 0; i<code.length();i++){
		if (code[i]<='Z'&&code[i]>='A'){
			value+=(code[i]-'A'+11)*((int)pow(2,i))%17;
		}
		if(code[i]<='9'&&code[i]>='0'){
			value += (code[i]-'0')*((int)pow(10,i))%29;
		}
		
	}
	value = value%17;
	return value;
	
}

int CourseTable::myhash(const Course& x)const{
	return myhash(x.get_code());
}


void CourseTable::print() {
        for (int i =0 ;i<_size; i++){
                cout << i <<endl;
                const list<Course>&  whichList = theLists[i];
                list<Course>::const_iterator itr = whichList.begin();
                while (itr != whichList.end()){
                        cout<<itr->get_code()<<endl;
                        ++itr;
                }
        }

}

void CourseTable::save(string name){
	ofstream fout(name.c_str(),std::fstream::app );
	if (fout.is_open()){
		list<Course>::iterator itr;
		for (int i =0 ;i<_size;i++){
			itr = theLists[i].begin();
			while (itr != theLists[i].end()){
				fout<<"course"<<endl;
				fout<< itr->get_code()<<endl;
				fout<< itr->get_name()<<endl;
				fout<< itr->get_credit()<<endl;
				++itr;	
			}
		}		
	}


}
