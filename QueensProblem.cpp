#include <bits/stdc++.h>
using namespace std;

#define size 4

bool inBounds(int r, int c){
	return ((r>=0) && (r<size) && (c>=0) && (c<size));
}

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

bool check(int r, int c, int a[][size]){
	for(int i=0;i<size;i++){
		for(int j=0;j<4;j++){
			if(inBounds(r+dx[j]*i, c+dy[j]*i) && a[r+dx[j]*i][c+dy[j]*i]!=-1){ return false;}
		}
	}
	for(int i=0; i<size; i++){
		if(inBounds(r,c-i)&&(a[r][c-i]!=-1)) return false;
		if(inBounds(r,c+i)&&a[r][c+i]!=-1) return false;
		if(inBounds(r-i,c)&&(a[r-i][c]!=-1)) return false;
		if(inBounds(r+i,c)&&a[r+i][c]!=-1) return false;
	}
	return true;
}

bool completed(int column, int a[][size]){
	if(column==size) return true;
	for(int i=0; i<size; i++){
		if(!check(i, column, a)) {continue;}
		a[i][column] = column;
		if(completed(column+1,a)) return true;
		a[i][column] = -1;
	}
	return false;
}

int main(){
	int a[][size] = {{-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}};
    completed(0,a);
    for(int i=0; i<size; i++){
    	for(int j=0; j<size; j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
}
