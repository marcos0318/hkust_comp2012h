#include <iostream>
#include <assert.h>
#include <cstddef>
#include <cstdlib>
#ifndef	RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H
template<typename T> class rq_iterator;
//Definations of the container


template<typename T> 
class RandomizedQueue{
public:
	typedef rq_iterator<T>  Iterator;
public:
	RandomizedQueue();
	RandomizedQueue(const RandomizedQueue<T>& x );
	~RandomizedQueue();

	bool isEmpty();
	int size();
	
	void enqueue(const T& x);
	T dequeue();
	T sample();
	
	rq_iterator<T>& iterator();
	RandomizedQueue<T>& operator=(const RandomizedQueue<T>& x);
private:
	T* front;//The queue is in a dynamic array 
	int cap;//The capability of the array 
	int n;//The number of item in the array
	void resize(int capability);//adjust the size of cap
};



//iterator
template<typename T>
class rq_iterator {
friend class RandomizedQueue<T>;
public: 
	rq_iterator(T* &start, int n );
	int* creatcopy(int n);	

	T& operator*();
	rq_iterator& operator++();	
	bool operator==(const rq_iterator &other) { 
		return pos == other.pos; }
	bool operator!=(const rq_iterator &other) { 
		return pos != other.pos; }




	rq_iterator &operator=(const rq_iterator &other) { 
		if (&other == this) return *this;
		delete[] copy;
		int* n_copy = new int[other.pos];
		for (int i = 0; i < other.pos; i++)
			n_copy[i] = other.copy[i];
		copy = n_copy;
		begin = other.begin;			
		pos = other.pos;
		return *this;
	}





private:
	int pos;
	int* copy;
	T* begin;
};

//implementation 


template <typename T> 
RandomizedQueue<T>::RandomizedQueue() : n(0), cap(2) {
	srand(time(NULL));
	front = new T[2];
}

template <typename T> 
RandomizedQueue<T>::~RandomizedQueue() {
	delete[] front;
}

template <typename T> 
RandomizedQueue<T>::RandomizedQueue(const RandomizedQueue& x) : front(new T[x.n]),n(x.n), cap(x.cap)
{
	for (int i = 0; i < x.n; i++)
		front[i] = x.front[i];
}

template <typename T> 
RandomizedQueue<T> & RandomizedQueue<T>::operator=(const RandomizedQueue& x) {
	if (this == &x) return *this;

	delete[] front;

	T *new_a = new T[x.n];

	for (int i = 0; i < x.n; i++)
		new_a[i] = x.front[i];

	front = new_a;
	n = x.n;
	cap = x.cap;

	return *this;
}

template <typename T> 
bool RandomizedQueue<T>::isEmpty() {
	return (n == 0);
}

template <typename T> 
int RandomizedQueue<T>::size() {
	return n;
}


template <typename T>
void RandomizedQueue<T>::enqueue(const T& x){
	if (n == cap) resize(2 * cap);
	front[n++] = x;
}




template <typename T>
T RandomizedQueue<T>::dequeue(){
	assert(!isEmpty());
	int x = rand()%n;
	
	T tmp = front[x];
	front[x]=front[--n];
	if(n>0&&n==cap/4)resize	(cap/2);
	return tmp;	
}


template <typename T>
void RandomizedQueue<T>::resize(int capacity){
	T* tmp = new T[capacity];
	for (int i = 0; i<n ; i++)tmp[i] = front[i];
	delete [] front;
	front = tmp;
	cap = capacity;

}


template <typename T>
T RandomizedQueue<T>::sample(){
	assert(!isEmpty());
	int x = rand()%n;
	return front[x];
	


}


int uniform(int x){
	return rand()%x;

}

void shuffle(int* arr, int N){
	for (int i = 0; i < N; i++) {
		int r = i + uniform(N - i);
		int temp = arr[i];
		arr[i] = arr[r];
		arr[r] = temp;
	}
}


template <typename T>
rq_iterator<T>& RandomizedQueue<T>::iterator(){
	rq_iterator<T>* rqip = new rq_iterator<T>(front,n);
	
	return *rqip;
}


//implementation of iterator

template<typename T>
rq_iterator<T>::rq_iterator(T* &start, int n)
	:begin(start),pos(n)
{
	copy = creatcopy(n);

}


template<typename T>
int* rq_iterator<T>::creatcopy(int N){
	if (N==0)return NULL;
	int* tmp = new int[N];
	for (int i = 0; i<N ;i++)tmp[i]=i;
	shuffle(tmp, N);
	return tmp;
}

template<typename T>
T& rq_iterator<T>::operator*(){
	return *(begin+copy[pos-1]);
}

template<typename T>
rq_iterator<T>& rq_iterator<T>::operator++(){
	pos--;
	return *this;
	
}


































#endif
