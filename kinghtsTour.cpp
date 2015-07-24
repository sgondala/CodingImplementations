	/*
	Solving knights tour using backtracking
	*/

	#include <bits/stdc++.h>
	using namespace std;

	#define size 6

	int dr[] = {1,1,2,2,-1,-1,-2,-2};
	int dc[] = {2,-2,1,-1,2,-2,1,-1};

	bool check(int r, int c){
		return ((r>=0) && (r<size) && (c>=0) && (c<size));
	}

	bool f(int r, int c, vector<vector<int> > &time, int count){
		time[r][c] = count;
		if(count == size*size-1) return true;
		for(int i=0; i<8; i++){
			if(check(r+dr[i],c+dc[i]) && (time[r+dr[i]][c+dc[i]]==-1)){
				if(f(r+dr[i],c+dc[i],time,count+1)){return true;}
			}
		}
		time[r][c] = -1;
		return false;
	}

	int main(){
		vector<vector<int> > time(size, vector<int>(size,-1));
		f(2,2,time,0);
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout<< time[i][j] <<" ";
			}
			cout<<endl;
		}
	}