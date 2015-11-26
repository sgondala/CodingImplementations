#include <bits/stdc++.h>
using namespace std;

// Default priority queue has push, pop, top, size
// This file is to show how an already existing class can be inherited,

template<class T> 
class min_priority_queue:public priority_queue<T>{ //See that we don't put min_priority_queue<T> as name
public:
	void push(T val){
		priority_queue<T>::push(-val);
	}
	T top(){
		return -priority_queue<T>::top();
	}
};


// int main(){
// 	min_priority_queue<int> all;
// 	all.push(4);
// 	cout<< all.size() <<endl;
// }