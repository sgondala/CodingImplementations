#include <bits/stdc++.h>
using namespace std;

vector<int> visited, parent, startTime, minVal;
vector<bool> isArt;
vector<vector<int> > edges;
int globalTime;

void startDfs(int index){
	
	globalTime++;
	startTime[index] = globalTime;
	minVal[index] = globalTime;
	int children = 0;
	
	for(int i=0; i<edges[index].size(); i++){
		int child = edges[index][i];
		
		if(visited[child]==0){
			visited[child] = 1;
			parent[child] = index;
			children++;
			startDfs(child);
			minVal[index] = min(minVal[index], minVal[child]);
		
			if(parent[index]==-1 && children>1){
				isArt[index] = true;
			}

			if(parent[index]!=-1 && (minVal[child] >= startTime[index])){
				isArt[index] = true;
			}
			
		}

		else if(child!=parent[index]){
			minVal[index] = min(minVal[index], minVal[child]);
		}
	}
	visited[index] = 2;
}

int main(){
	int n;
	cin>>n;
	edges = vector<vector<int> >(n,vector<int>());
	int m;
	cin>>m;
	for(int i=0; i<m ;i++){
		int start, end;
		cin>>start>>end;
		edges[start].push_back(end); //Considering directed graphs
		edges[end].push_back(start); //Considering directed graphs
	}
	globalTime = 0;
	visited = vector<int>(n,0);
	parent = vector<int>(n,-1);
	startTime = vector<int>(n);
	minVal = vector<int>(n);
	isArt = vector<bool>(n, false);
	for(int i=0; i<n; i++){
		if(visited[i]==0){
			visited[i] = 1;
			startDfs(i);
		}
	}

	for(int i=0; i<n; i++){
		if(isArt[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}