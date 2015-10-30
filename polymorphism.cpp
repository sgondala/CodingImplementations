#include <bits/stdc++.h>
using namespace std;

class alpha{
public:
	int val;
	alpha(int a){
		val = a;
	}
	virtual void printClass(){
		cout<<"Alpha"<<endl;
	}
	virtual void printNothing() = 0;
};

class beta: public alpha{
public:
	beta(int a):alpha(a){};
	void printClass(){
		cout<<val << " Beta"<<endl;
	}
	void printNothing(){ //Doesn't execute if this is not written
		cout<<"LOLz"<<endl;
	}
};

int main(){
	// alpha al; // This can't be done as it has a pure virtual func 
	alpha* a;
	beta b(3);
	a = &b;
	a->printClass(); //If printClass is described as virtual, prints beta - else alpha
	a->printNothing();
}