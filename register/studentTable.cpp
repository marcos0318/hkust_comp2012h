#include "studentTable.h"
StudentTable::StudentTable(int size)
	:_size(size)
{
	vector<list<Student> > * vp = new vector<list<Student> >(_size);
	
	theLists = *vp;
}


bool StudentTable::contains(const string& id)const
{
	const list<Student>&  whichList = theLists[myhash(id)];
	list<Student>::const_iterator itr = find_if(whichList.begin(), whichList.end(),Same_id(id));//itr have to be a const iterator because the method is const, and the objects are treated as const
	if (itr != whichList.end())return true;
	else return false;
}

const Student* StudentTable::find_student(const string& id)const
{
	const list<Student>&  whichList = theLists[myhash(id)];
	list<Student>::const_iterator itr = find_if(whichList.begin(), whichList.end(),Same_id(id));//itr have to be a const iterator because the method is const, and the objects are treated as const
	if (itr != whichList.end())return &(*itr);
	else return 0;
}
bool StudentTable::contains(const Student& student)const{
	return contains(student.get_id());
}

void StudentTable::makeEmpty(){
	for(size_t i = 0; i< theLists.size(); i++){
		theLists[i].clear();
	}
}

bool StudentTable::insert(const Student& x){
//We check the duplication in outer structure
	list<Student>& whichList = theLists[myhash(x)];
	list<Student>::iterator itr = find(whichList.begin(), whichList.end(),x);
	if (itr != whichList.end())return false;
	whichList.push_back(x);
	whichList.sort();
	return true;
}

bool StudentTable::remove(const string& id){
	list<Student>& whichList = theLists[myhash(id)];
	list<Student>::iterator itr = find_if(whichList.begin(), whichList.end(),Same_id(id));
	if (itr == whichList.end())return false;
	whichList.erase(itr);
	return true;
}

int StudentTable::myhash(const string& id)const{
	int value = 0;
	for(unsigned i = 0; i < id.length();i++){
		value += (id[i]-'0')*((int)pow(10,i))%29;
	}
	value = value%29;
	return value;
}

int StudentTable::myhash(const Student& student)const{
	return myhash(student.get_id());
}

void StudentTable::print() {
	for (int i =0 ;i<_size; i++){
		cout << i <<endl;
		const list<Student>&  whichList = theLists[i];
		list<Student>::const_iterator itr = whichList.begin();
		while (itr != whichList.end()){
			cout<<itr->get_id()<<endl;
			++itr;
		}
	} 
	
}


void StudentTable::save(string name){
	ofstream fout(name.c_str());
	if ( !fout.is_open()){
		cout << "cannot open the file"<<endl;
		return;
	}
	else {
	fout <<"database"<<endl;
	list<Student>::iterator itr;
	for (int i = 0; i<_size; i++){
		itr = theLists[i].begin();
		while(itr != theLists[i].end()){
			fout<<"student"<<endl;
			fout<<itr->get_id()<<endl;
			fout<<itr->get_name()<<endl;
			fout<<itr->get_year()<<endl;
			fout<<itr->get_gender()<<endl;
			++itr;
		}
	}
	cout<<"saved"<<endl;
	

	}


}
