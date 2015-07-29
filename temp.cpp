#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > v(){
	vector<vector<int> > a(2,vector<int>(3,1));
	return a; 
}

int** a(){
	int **c = new int*(3);
	for(int i=0; i<3; i++){
		c[i] = new int(4);
	}
	return c;
}

int main(){
	int** temp = a();
	cout<< sizeof(temp)/sizeof(temp[0][0]) <<endl;
}