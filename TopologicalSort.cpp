#include <bits/stdc++.h>
using namespace std;

/*
Inverse sort of dfs-complete time
*/

int t= 0;
pair<int,int> times[10];

void dfsSingle(int current, int graph[][10], pair<int,int> times[],
		 int parent[], int seenVertices[], int explored[]){
	times[current].first = t;
	t++;
	for(int i=explored[current]+1; i<10; i++){
		if(graph[current][i]==1 && seenVertices[i]==0){
			cout<<current<<" "<<i<<" "<<"Tree edge"<<endl;
			seenVertices[i]=1;
			parent[i] = current;
			explored[current] = i;
			dfsSingle(i,graph,times,parent,seenVertices, explored);
		}
		else if(graph[current][i]==1 && seenVertices[i]==1){
			cout<<current<<" "<<i<<" "<<"Back edge"<<endl;
		}
		else if(graph[current][i]==1 && seenVertices[i]==2){
			if(times[i].second<times[current].first){
				cout<<current<<" "<<i<<" "<<"Cross edge"<<endl;
			}
			else{
				cout<<current<<" "<<i<<" "<<"Forward edge"<<endl;
			}
		}
	}
	times[current].second = t;
	t++;
	seenVertices[current] = 2;
}

void dfs(int graph[][10], pair<int,int> times[], 
			int parent[], int seenVertices[], int explored[]){
	for(int i=0; i<10; i++){
		if(seenVertices[i]==0){
			seenVertices[i] = 1;
			dfsSingle(i,graph,times,parent,seenVertices, explored);			
		}
	}
}

bool compare(int a, int b){
	return times[a].second>times[b].second;
}

int main(){
	int graph[10][10];
	memset(graph, 0, sizeof(graph));
	int seenVertices[10];
	memset(seenVertices, 0, sizeof(seenVertices));
	int parent[10];
	memset(parent, -1, sizeof(parent));
	memset(times, -1, sizeof(times));
	int explored[10];
	memset(explored, -1, sizeof(explored));
	graph[1][2] = 1;
	graph[2][3] = 1;
	graph[4][3] = 1;
	graph[3][6] = 1;
	graph[4][5] = 1;
	graph[5][6] = 1;
	graph[1][8] = 1;
	graph[2][8] = 1;
	graph[7][8] = 1;
	dfs(graph, times, parent, seenVertices, explored);
	vector<int> topologicalSort;
	for(int i=0; i<10; i++){
		topologicalSort.push_back(i);
	}
	sort(topologicalSort.begin(), topologicalSort.end(), compare);
	for(int i=0; i<10; i++){
		cout<< topologicalSort[i]<<endl;
	}
}