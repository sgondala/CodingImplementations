#include <bits/stdc++.h>
using namespace std;

#define N 20

int a[N];
int segArray[2*N];

void buildTree(int node, int start, int end){
	if(start>end){return;}
	if(start==end){
		segArray[node] = a[start];
		return;
	}
	buildTree(2*node, start, (start+end)/2);
	buildTree(2*node + 1, (start+end)/2 + 1, end);
	segArray[node] = max(segArray[2*node], segArray[2*node + 1]);
}

// Increase all of [valStart,valEnd] by val
void changeVal(int node, int start, int end, int valStart, int valEnd, int val){
	if((start>end) || (valEnd<start) || (valStart>end)){return;}
	if(start==end){
		segArray[node] += val;
		return;
	}
	changeVal(2*node, start, (start+end)/2, valStart, valEnd, val);
	changeVal(2*node+1, (start+end)/2 + 1, end, valStart, valEnd, val);
	segArray[node] = max(segArray[2*node], segArray[2*node+1]);
}

int query(int node, int start, int end, int valStart, int valEnd){
	if((start>end)||(start>valEnd)||(end<valStart)){
		return -100000000; // Some min no as we have max seg tree
	}
	if(start>=valStart && end<=valEnd){
		return segArray[node];
	}
	int a = query(2*node, start, (start+end)/2, valStart, valEnd);
	int b = query(2*node+1, (start+end)/2+1, end, valStart, valEnd);
	return max(a,b);
}


int main(){
	for(int i=0; i<N; i++){
		a[i] = 1;
	}
	buildTree(1,0,N-1);
	changeVal(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	changeVal(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	changeVal(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

	cout << query(1, 0, N-1, 0, N-1) << endl; 
}