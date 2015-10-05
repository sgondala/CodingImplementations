// Headers
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

int val1, val2;
int globalTime = 0;

int nodeFound = -1;
bool val1Found = false;
bool val2Found = false;
int startTimeVal1 = -1, startTimeVal2 = -1;
int endTimeVal1 = -1, endTimeVal2 = -1;

void DFS(int node, vector<int> &val, vector<int> &visited, vector<int> &startTime, 
			vector<int> &endTime, vector<vector<int> > edges){
	startTime[node] = globalTime;
	globalTime++;

	for(int i=0; i<edges[node].size(); i++){
		if(visited[edges[node][i]]==0){
			visited[edges[node][i]] = 1;
			DFS(edges[node][i], val, visited, startTime, endTime, edges);
		}
	}

	endTime[node] = globalTime;
	globalTime++;

	if(val[node]==val1){
		val1Found = true;
		startTimeVal1 = startTime[node];
		endTimeVal1 = endTime[node];
	}
	if(val[node]==val2){
		val2Found = true;
		startTimeVal2 = startTime[node];
		endTimeVal2 = endTime[node];
	}

	if(val1Found && val2Found){
		if(startTime[node]<=startTimeVal1 && startTime[node]<=startTimeVal2 
			&& endTime[node]>=endTimeVal1 && endTime[node]>=endTimeVal2 && nodeFound==-1){
			nodeFound = node;
		}
	}
}

int main(){
	int n, e;
	cin>>n>>e;
	vector<int> val(n);
	vector<int> startTime(n), endTime(n);
	vector<int> visited(n,0);
	vector<vector<int> > edges(n, vector<int>());
	for(int i=0; i<n; i++){
		cin>>val[i];
	}
	for(int i=0; i<e; i++){
		int start, end;
		cin>>start>>end;
		start--;
		end--;
		edges[start].pb(end);
		edges[end].pb(start);
	}
	cin>>val1>>val2;
	visited[0] = 1;
	DFS(0, val, visited, startTime, endTime, edges);
	cout<< val[nodeFound] <<endl;
}


// Input
// 7
// 6
// 1 2 3 4 5 6 7
// 1 2 
// 1 3 
// 2 4
// 2 5 
// 3 6
// 3 7