#include <bits/stdc++.h>
using namespace std;

void change(int a[][2]){
	a[1][1] = 10;
}

int main(){
	int a[][2] = {{1,2},{3,4}};
	change(a);
	cout<< a[1][1] <<endl;
}