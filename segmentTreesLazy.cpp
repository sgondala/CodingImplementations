#include <bits/stdc++.h>
using namespace std;

#define N 20

int a[N];
int segTree[64]; //2 times the next biggest power of 2
int lazy[64];

void buildTree(int node, int start, int end){

	if(start>end){
		return;
	}

	if(start==end){
		segTree[node] = a[start];
		return;
	}

	buildTree(node*2, start, (start+end)/2);
	buildTree(node*2 + 1, (start+end)/2+1, end);
	segTree[node] = max(segTree[2*node], segTree[2*node + 1]); //MaxSegTree building

}

// Increases value of all elements in range by val
void changeVal(int node, int start, int end, int startVal, int endVal, int val){
	
	if((start>end) || (end<startVal) || (start>endVal)){
		return;
	}

	if(lazy[node]!=0){
		segTree[node] += lazy[node];
		if(start!=end){
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if((start>=startVal) && (end<=endVal)){
		segTree[node] += val;
		if(start!=end){
			lazy[2*node] += val;
			lazy[2*node + 1] += val;
		}
		return;
	}

	changeVal(2*node, start, (start+end)/2, startVal, endVal, val);
	changeVal(2*node + 1, (start+end)/2 + 1, end, startVal, endVal, val);
	segTree[node] = max(segTree[2*node], segTree[2*node + 1]);
}

int query(int node, int start, int end, int startVal, int endVal){

	if((start>end) || (start>endVal) || (end<startVal)){
		return -100000000;
	}

	if(lazy[node]!=0){
		cout<<node<<" HAHAA"<<endl;
		segTree[node] += lazy[node];
		if(start!=end){
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if((start>=startVal) && (end<=endVal)){
		return segTree[node];
	}

	int leftVal = query(2*node, start, (start+end)/2, startVal, endVal);
	int rightVal = query(2*node + 1, (start+end)/2 + 1, end, startVal, endVal);
	int retVal =  max(leftVal, rightVal);
	return retVal;
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