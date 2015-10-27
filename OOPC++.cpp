#include <bits/stdc++.h>
using namespace std;

class box{
public:
	int l,b,h;
	static int boxCount;

	box(int,int,int); //Constructor 1 
	box(int a, int b): l(a), b(b), h(0){}; //Constructor 2
	box();
	~box(); //Destructor
	box(const box &);
	static int getCount(){
		return boxCount;
	}
};

box::box(int a, int b, int c) : l(a),b(b),h(c){} //This too can be used as constructor

box::box(){
	boxCount++;
};

box::~box(){
}

box::box(const box &inputBox){
	l = 1;
	b = inputBox.b;
	h = 1;
}

int box::boxCount = 0;

int main(){
    cout << box::getCount() << endl;
	// cout << box::getCount <<endl;
	// box myBox(1,2,3);

	//Copy constructor works here
	// box myBox2 = myBox;
	
	// Assignment operator works here !!!
	box myBox3;
	// myBox3 = myBox;
	cout<< box::getCount() <<endl;

	// cout<< myBox3.boxCount <<endl;
} //Destructor gets called