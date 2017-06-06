#include <iostream>
#include <cstdlib>
#include <string>
#include "randomized_queue.h"
using namespace std;
int main(int argc, char** argv ){
	int k = atoi(argv[1]);
	string x;
	RandomizedQueue<string> rq;
	while (cin >> x){
		rq.enqueue(x);
	}	

	for (int i = 0 ; i<k ;i++)cout<<rq.dequeue()<<endl;




	return 0;
}
