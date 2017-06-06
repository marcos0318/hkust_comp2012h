#include<assert.h>
#include<cstddef>
#ifndef DEQUE_H
#define DEQUE_H
//The class defination of the container
template <typename T> class Deque_node;
template <typename T> class Deque_iterator;
template<typename T>
class Deque {
public:
	typedef Deque_iterator<T> Iterator;

public:
	Deque();
	bool isEmpty();

	int size();
	void addFirst(const T& x);
	void addLast(const T& x);
	T removeFirst();
	T removeLast();
	Deque_iterator<T>& iterator();	


private:
	Deque_node<T> *head, *tail; 
};



//The defiantion of the class of the node in deque
template <typename T>
class Deque_node{
friend class Deque<T>;
friend class Deque_iterator<T>;
public:
	Deque_node(const T& t);

private:
	T value;
	Deque_node *prev, *curr, *next;

};




//The iterator of the Deque
template <typename T>
class Deque_iterator{
	friend class Deque<T>;

public:
	Deque_iterator(Deque_iterator<T>& a);
	Deque_iterator(Deque_node<T>*);
	Deque_iterator();

	T& operator*();
	Deque_iterator<T> operator++();
	Deque_iterator<T> operator++(int);
	Deque_iterator<T> operator--();
	Deque_iterator<T> operator--(int);
	bool operator==(const Deque_iterator<T>& other){
		return (*pointee == *(other.pointee));
	}
	bool operator!=(const Deque_iterator<T>& other){
		return (!(*this==other));
	}	


private: 
	Deque_node<T>* pointee;

};



//The implementation of the deque
template<typename T>
Deque<T>::Deque():head(NULL),tail(NULL){}

template<typename T>
bool Deque<T>::isEmpty(){
        if (head == NULL)return 1;
        else return 0;

}

template<typename T>
int Deque<T>::size(){
        if (isEmpty())return 0;
        else {
                int count = 1;
                Deque_node<T> *ptr = head;
                while(ptr->next != NULL){
                        ptr = ptr->next;
                        count ++;
                }
                return count;
        }


}

template<typename T>
void Deque<T>::addFirst(const T& x){
        Deque_node<T>* dnp = new Deque_node<T>(x);
        if (isEmpty()){
                dnp->prev = NULL;
                dnp->curr = dnp;
                dnp->next = NULL;
                head = dnp;
                tail = dnp;
        }
        else {
                dnp->prev = NULL;
                dnp->curr = dnp;
                dnp->next = head;
		head->prev = dnp;
                head = dnp;
        }

}


template<typename T>
void Deque<T>::addLast(const T& x){
        Deque_node<T>* dnp = new Deque_node<T>(x);
        if (isEmpty()){
                dnp->prev = NULL;
                dnp->curr = dnp;
                dnp->next = NULL;
                head = dnp;
                tail = dnp;
        }
        else {
                dnp->prev = tail;
                dnp->curr = dnp;
                dnp->next = NULL;
		tail->next = dnp;
                tail = dnp;
        }
}

template<typename T>
T Deque<T>::removeFirst(){
	assert(size());
	if (size()>1){
        	 T tmp = head->value;
       		 Deque_node<T>* dnp = head;


       		 head = head->next;
       		 head->prev = NULL;
       		 delete dnp;
        	 return tmp;
	}
	else {
		T tmp = head->value;
		delete head;
		head = tail = NULL;
		return tmp;
		
	}
}

template<typename T>
T Deque<T>::removeLast(){
	assert(size());
	if(size()>1){
        	T tmp = tail->value;
        	Deque_node<T>* dnp = tail;

        	tail = tail->prev;
        	tail->next = NULL;
        	delete dnp;
        	return tmp;
	}
	else {
		T tmp = tail->value;
		delete head;
		head = tail = NULL;
		return  tmp;
	}

}
template<typename T>
Deque_iterator<T>& Deque<T>::iterator(){
        Deque_iterator<T>* dip = new Deque_iterator<T>(head);
        return *dip;
}







//The implementation of the deque_note

template<typename T>
Deque_node<T>::Deque_node(const T& t):value(t)
{
        prev = curr = next = NULL;

}


//The implementation of deque_iterator



template<typename T>
Deque_iterator<T>::Deque_iterator(Deque_iterator<T>&a)
        :pointee(a.pointee){
}

template<typename T>
Deque_iterator<T>::Deque_iterator(Deque_node<T>* x)
        :pointee(x){}

template<typename T>
Deque_iterator<T>::Deque_iterator():pointee(NULL){}


template<typename T>
T& Deque_iterator<T>::operator*(){
        return pointee->value;
}

template<typename T>
Deque_iterator<T> Deque_iterator<T>::operator++(){
        assert(pointee != NULL);
        pointee = pointee->next;
        return *this;
}

template<typename T>
Deque_iterator<T> Deque_iterator<T>::operator++(int){
        assert(pointee != NULL);
        Deque_iterator temp(pointee);
        pointee = pointee->next;
        return temp;
}

template<typename T>
Deque_iterator<T> Deque_iterator<T>::operator--(){
        assert(pointee != NULL);
        pointee = pointee->prev;
        return *this;
}


template<typename T>
Deque_iterator<T> Deque_iterator<T>::operator--(int){
        assert(pointee != NULL);
        Deque_iterator temp(pointee);
        pointee = pointee->prev;
        return temp;
}






#endif
