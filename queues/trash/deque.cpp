#include "deque.h"
#include <cstddef>
#include <assert.h>
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
		while(ptr->prev != NULL){
			ptr = ptr->prev;
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
		tail = dnp;
	}
}

template<typename T>
T Deque<T>::removeFirst(){
	T tmp = head->value;
	Deque_node<T>* dnp = head;
	

	head = head->next;
	head->prev = NULL;
	delete dnp;
	return tmp;

}

template<typename T>
T Deque<T>::removeLast(){
	T tmp = tail->value;
	Deque_node<T>* dnp = tail;

	tail = tail->prev;
	tail->next = NULL;
	delete dnp;
	return tmp;


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
	:pointee(a.pointee){}

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







































