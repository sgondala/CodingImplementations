#include <bits/stdc++.h>
using namespace std;

void bfs(int current, int parent[], int seenVertices[], int graph[][10]){
	queue<int> indices;
	seenVertices[current] = 1;
	indices.push(current);
	while(!indices.empty()){
		int currentIndex = indices.front();
		for(int i=0; i<9; i++){
			if(graph[currentIndex][i] && (seenVertices[i]==0)){
				parent[i] = currentIndex;
				seenVertices[i] = 1;
				indices.push(i);	
			}
		}
		seenVertices[current] = 2;
		indices.pop();
	}
}

int main(){
	int graph[10][10];
	memset(graph, 0, sizeof(graph));
	int seenVertices[10];
	memset(seenVertices, 0, sizeof(seenVertices));
	int parent[10];
	memset(parent, -1, sizeof(parent));
	graph[1][2] = 1;
	graph[2][1] = 1;
	graph[1][3] = 1;
	graph[3][1] = 1;
	graph[2][4] = 1;
	graph[4][2] = 1;
	graph[3][4] = 1;
	graph[4][3] = 1;
	graph[4][6] = 1;
	graph[6][4] = 1;
	graph[1][2] = 1;
	graph[1][5] = 1;
	graph[5][1] = 1;
	graph[5][6] = 1;
	graph[6][5] = 1;
	bfs(1, parent, seenVertices, graph);
	cout<<parent[2]<<" "<<parent[3]<<" "<<parent[4]<<" "<<parent[6]<<endl;
}