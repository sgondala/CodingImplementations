#include <bits/stdc++.h>
using namespace std;

#define vname(x) #x

struct stackStruct{
	stack<int> valStack;
	int stackNumber;
	stackStruct(int _val){
		valStack = stack<int>();
		stackNumber = _val;
	}
	void push(int _val){
		valStack.push(_val);
	}
	void pop(){
		valStack.pop();
	}
	int top(){
		return valStack.top();
	}
	int getNumber(){
		return stackNumber;
	}
};

void moveSingle(stackStruct &a, stackStruct &b){
	cout<<"Moving "<<a.top()<<" from "<<a.stackNumber<<" to "<<b.stackNumber<<endl;
	int val = a.top();
	a.pop();
	b.push(val);
}

void printMotion(stackStruct &start, stackStruct &inter, stackStruct &dst, int n){
	if(n==1){
		moveSingle(start, dst);
		return;
	}
	printMotion(start, dst, inter, n-1);
	moveSingle(start, dst);
	printMotion(inter, start, dst, n-1);
}

int main(){
	int n;
	cin>>n;
	stackStruct start(1), dst(3), inter(2);
	for(int i=n; i>=1; i--){
		start.push(i);
	} 
	printMotion(start, inter, dst, n);
}