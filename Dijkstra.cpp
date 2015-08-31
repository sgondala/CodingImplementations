#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int v,e,s; //vertices, edges, source
	cin>>v>>e>>s;
	s--;
	vector<vector<pair<int,int> > > edges(v,vector<pair<int,int> >());
	for(int i=0; i<e; i++){
		int start, end, dist;
		cin>>start>>end>>dist;
		edges[start-1].push_back(make_pair(end-1,dist));
	}
	vector<int> parent(v,-1);
	vector<int> dist(v,1e8);
	dist[s]=0;
	set<pair<int,int> > dijkstra;
	for(int i=0; i<v; i++){
		dijkstra.insert(make_pair(dist[i],i));
	}
	while(!dijkstra.empty()){
		int temp = dijkstra.begin()->second;
		dijkstra.erase(dijkstra.begin());
		for(int i=0; i<edges[temp].size(); i++){
			int nodeNew = edges[temp][i].first;
			int weight = edges[temp][i].second;
			if(dist[nodeNew] > dist[temp] + weight){  //Relaxing step
				dijkstra.erase(dijkstra.find(make_pair(dist[nodeNew],nodeNew)));
				dist[nodeNew] = dist[temp] + weight;
				dijkstra.insert(make_pair(dist[nodeNew], nodeNew));
				parent[nodeNew] = temp;
			}
		}
	}
	for(int i=0; i<v; i++){
		cout<<i+1<<" "<<dist[i]<<endl;
	}
}