#include <stdio.h>
#include "deque.h"
#include <iostream>
using namespace std;
int main(){
	Deque<char> dq;
	char x;
	bool flag = 1;
	while (cin >> x){
		dq.addLast(x);	
	}
	int n = dq.size();
	if (dq.size()%2)cout<<"false"<<endl;
	else {
		while(dq.size()>0){
			char a = dq.removeFirst();
			char b = dq.removeLast();
			if (a =='A')flag *= (b=='T');	
			else if (a =='G')flag *= (b=='C');	
			else if (a =='C')flag *= (b=='G');	
			else if (a =='T')flag *= (b=='A');	
			else flag = 0;

		}

		if (flag)cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}








	return 0;



}


