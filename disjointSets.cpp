#include <bits/stdc++.h>
using namespace std;

void makeset(int i, int *parent, int *rank){
	parent[i] = i;
	rank[i] = 0;
}

int findParent(int i, int* parent){
	if(parent[i]==i){return i;}
	parent[i] = findParent(parent[i], parent);
	return parent[i];
}

void linkBoth(int pi, int pj, int* parent, int* rank){
	if(pi==pj){return;}
	if(rank[pi]<rank[pj]){
		parent[pi] = pj;
	}
	else{
		parent[pj] = pi;
		if(rank[pi]==rank[pj]){rank[pi]++;}
	}
	return;
}

void unionSet(int i, int j, int* parent, int* rank){
	linkBoth(findParent(i,parent), findParent(j, parent), parent, rank);
}

int main(){
	int n = 5;
	int parent[n+1];
	int rank[n+1];
	for(int i=1; i<=n; i++){makeset(i,parent,rank);}
	unionSet(1,2,parent,rank);
	unionSet(3,4,parent,rank);
	cout<<findParent(1,parent)<<endl;
	cout<<findParent(3,parent)<<endl;
	unionSet(1,3,parent,rank);
	cout<<findParent(3,parent)<<endl;
	unionSet(5,3,parent,rank);
	cout<<findParent(5,parent)<<endl;
}