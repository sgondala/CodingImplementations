#include <bits/stdc++.h>
using namespace std;

class shape{
private:
	int width, height;
public:
	shape(int a, int b){
		width = a;
		height = b;
		cout<<" Non default constructor"<<endl;
	}
	shape(){
		cout << "Hey" <<endl;
	} // This is required because for rectangle, this is needed
	void setValues(int a, int b){
		width = a;
		height = b;
	}
	int getWidth(){
		return width;
	}
	int getHeight(){
		return height;
	}
};

class rectangle: public shape{ //Shape is base/Super class and Rectangle is derived/Sub class
// Public shape - Protected of base is protected here, public is public here
// Protected shape - Protected and public of base are protected
// Private shape - Protected and public of base are private

public:
	//C1
	// rectangle(int a, int b){ //hey is printed, Default constructor is called
	// 	setValues(a,b);
	// }

	//C2
	rectangle(int a, int b) : shape(a,b){}; //Here specified constructor is called

	int getArea(){
		return getHeight()*getWidth();
	}
};


class alpha{
protected:
	int alphaVal;
public:
	void setAlphaVal(int val){
		alphaVal = val;
	}
	int getAlphaVal(){
		return alphaVal;
	}
};

class beta{
protected:
	int betaVal;
public:
	void setBetaVal(int val){
		betaVal = val;
	}
	int getBetaVal(){
		return betaVal;
	}
};

class gamma2: public alpha, public beta{ //Multiple Inheritance
public:
	int getProd(){temp
		return alphaVal*betaVal;
	}
};

int main(){
	rectangle a(2,3); 
	// Does not work - Reason - Constructors, destructors, friends, 
	// 							overload operators, copy constructors are not derived
	// rectangle a;
	// a.setValues(2,3);
	// cout<< a.getArea() <<endl;
	// cout<< a.getHeight() <<endl;
	// cout<<"-------------" <<endl;
	gamma2 gammaObj;
	gammaObj.setAlphaVal(2);
	gammaObj.setBetaVal(3);
	cout << gammaObj.getProd() <<endl;
}