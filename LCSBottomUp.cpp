#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

string a,b;
int aSize, bSize;
vector<vector<int> > lcs;
vector<vector<int> > path;
void fillLcs(){
	for(int i=0; i<=aSize; i++){
		lcs[i][0] = 0;
		path[i][0] = 0;
	}
	for(int j=0; j<=bSize; j++){
		lcs[0][j] = 0;
		path[0][j] = 0;
	}
	for(int i=1; i<=aSize; i++){
		for(int j=1; j<=bSize; j++){
			if(a[i-1]==b[j-1]){
				lcs[i][j] = 1+lcs[i-1][j-1];
				path[i][j] = 1; //diagonally up
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				if(lcs[i-1][j] > lcs[i][j-1]){path[i][j] = 2;} //up
				else{path[i][j] = 3;} //left
			}
		}
	}
}

void printLcs(){
	string s = "";
	int i=aSize, j=bSize;
	while(path[i][j]!=0){
		if(path[i][j]==1){
			s+=a[i-1];
			i--;
			j--;
		}
		else if(path[i][j]==2){
			i--;
		}
		else if(path[i][j]==3){
			j--;
		}
	}
	reverse(s.begin(), s.end());
	cout<< s <<endl;
}

int main(){
	cin>>a>>b;
	aSize = a.size();
	bSize = b.size();
	lcs = vector<vector<int> >(aSize+1, vector<int>(bSize+1,-1));
	path = vector<vector<int> >(aSize+1, vector<int>(bSize+1,-1));
	fillLcs();
	cout<< lcs[aSize][bSize] <<endl;
	printLcs();
}