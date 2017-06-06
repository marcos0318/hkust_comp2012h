#include "selectionTable.h"
void SelectionTable::print(){
        list<CourseSelection>::iterator itr;
        //_data
        cout << "Data:"<<endl;
        itr = _data.begin();
        while(itr != _data.end()){
                cout <<*itr<<" ";
                ++itr;
        }
        //id lists
        cout <<"first hash"<<endl;
        for (int i =0 ; i <_id_lists_size; i++){
                itr = id_lists[i].begin();
                if (itr != id_lists[i].end()){
                        cout <<i<<":"<<endl;;
                        while (itr != id_lists[i].end()){
                                cout << *itr<<endl;
                                ++itr;
                        }
                }
        }

        //code lists
        cout <<"second hash"<<endl;

        for (int i =0 ; i <_code_lists_size; i++){
                itr = code_lists[i].begin();
                if (itr != code_lists[i].end()){
                        cout <<i<<":"<<endl;;
                        while (itr != code_lists[i].end()){
                                cout << *itr<<endl;
                                ++itr;
                        }
                }
        }

}

void SelectionTable::save(string name){
	ofstream fout(name.c_str(), std::fstream::app);
	if(fout.is_open()){
		list<CourseSelection>::iterator itr = _data.begin();
		while (itr != _data.end()){
			fout << "selection"<<endl;
			fout << itr->get_id()<<endl;
			fout << itr->get_code()<<endl;
			fout << itr->get_mark()<<endl;
			++itr;
		}
	}

}                                   



//constructor
SelectionTable::SelectionTable(int id_lists_size, int code_lists_size)
	:_id_lists_size(id_lists_size),_code_lists_size(code_lists_size)
{
	vector<list< CourseSelection> >*vp1 = new vector<list< CourseSelection> >(_id_lists_size);
	id_lists = *vp1;
	vector<list< CourseSelection> >*vp2 = new vector<list< CourseSelection> >(_code_lists_size);
	code_lists = *vp2;
}


//accessors

const CourseSelection* SelectionTable::find_selection(const string& id, const string& code)const{
	const list< CourseSelection>& whichList = id_lists[hash_id(id)];//arcually you can use another table
	list< CourseSelection>::const_iterator itr = find_if(whichList.begin(),whichList.end(),Same_id_and_code(id, code));
	if (itr == whichList.end()){return 0;}
	else return &(*itr);

}


bool SelectionTable::contains(const string& id, const string& code)const{
	const list< CourseSelection>& whichList = code_lists[hash_code(code)];//arcually you can use another table
	list<CourseSelection>::const_iterator itr = find_if(whichList.begin(),whichList.end(),Same_id_and_code(id,code));
	if (itr != whichList.end()){return true;}
	else return false;

}

bool SelectionTable::contains(const CourseSelection& x)const{
        const list< CourseSelection>& whichList = id_lists[hash_id(x)];
        list< CourseSelection>::const_iterator itr = find(whichList.begin(),whichList.end(),x);
        if( itr != whichList.end()) return true;
	return false;
}



bool SelectionTable::contains_student(const string& id)const{
	list< CourseSelection>::const_iterator itr = find_if(_data.begin(),_data.end(),Same_id_selection( id));
	if (itr!=_data.end())return true;
	return false;
}

bool SelectionTable::contains_student(const Student& x)const {
	return contains_student(x.get_id());
}

bool SelectionTable::contains_course(const string& code)const{
	list< CourseSelection>::const_iterator itr = find_if(_data.begin(),_data.end(),Same_code_selection(code));
	if (itr != _data.end())return true;
	else return false;
}

bool SelectionTable::contains_course(const Course& x)const{
	return contains_course(x.get_code());
}


bool SelectionTable::insert(const CourseSelection& x){
//first you need to check whether it already there, but only need to check in one table	
	list< CourseSelection>& aList = id_lists[hash_id(x)];
	list< CourseSelection>::iterator itr = find_if(aList.begin(),aList.end(),Same_id_and_code(x));
	if( itr != aList.end()) return false;
//modify the first table
	aList.push_back(x);
	aList.sort();
//modify the second table
	
	list< CourseSelection>& bList = code_lists[hash_code(x)];
	 itr = find_if(bList.begin(),bList.end(),Same_id_and_code(x));
	if( itr != bList.end()) return false;
//modify the first table
	bList.push_back(x);
	bList.sort();
	
//modify the linked list
	_data.push_back(x);
	_data.sort();
	return true;
}	

bool SelectionTable::remove(const string& id, const string& code){
//Check if the selection exist
	list< CourseSelection>& aList = id_lists[hash_id(id)];
	list< CourseSelection>::iterator itr = find_if(aList.begin(),aList.end(),Same_id_and_code(id,code));
	if (itr == aList.end())return false;
	aList.erase(itr);


	list< CourseSelection>& bList = code_lists[hash_code(code)];
	itr = find_if(bList.begin(),bList.end(),Same_id_and_code(id,code));
	if (itr == bList.end())return false;
	bList.erase(itr);
	

	
	list<CourseSelection>::iterator it = find_if(_data.begin(), _data.end(),Same_id_and_code(id,code));
	_data.erase(it);	
	
	return true;
}

bool SelectionTable::remove(const CourseSelection& x){
	return remove(x.get_id(), x.get_code());
}


bool SelectionTable::remove(const string& id){
	//The first set of index
	list< CourseSelection>& aList = id_lists[hash_id(id)];
	list< CourseSelection>::iterator itr = aList.begin();
	while ( itr != aList.end()){
		if ( Same_id_selection(id)(*itr) ){
			itr = aList.erase(itr);
		}
		else ++itr;

	}
	//The second set of index

	for (int i= 0; i<_code_lists_size; i++){
		itr = code_lists[i].begin();
		while ( itr != code_lists[i].end()){
                	if(Same_id_selection(id)(*itr)){
                        itr = aList.erase(itr);
                	}
                	else ++itr;
        
       		 }	
	}
	
	//The list
	
	list<CourseSelection>::iterator it;
	it =  _data.begin();
	while (it != _data.end()){
		if (Same_id_selection(id)(*it))	{
			it = _data.erase(it);
		}
		else it++;
	
	}
	
	return true;
	
}

bool SelectionTable::remove(const Student& x){
	return remove(x.get_id());
}



int SelectionTable::hash_id(const string& id)const{
	int value = 0;
        for(unsigned i = 0; i < id.length();i++){
                value += (id[i]-'0')*((int)pow(10,i))%29;
        }
        value = value%29;
        return value;
}

int SelectionTable::hash_id(const CourseSelection& x)const {
	return hash_id(x.get_id());
}

int SelectionTable::hash_code(const string& code)const {
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

int SelectionTable::hash_code(const CourseSelection& x)const{
	return hash_code(x.get_code());
}
