#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000 

struct graph{ //Always vertices 1-n
	int v,e;
	vector<vector<pair<int,int> > > edges;
	graph(int v, int e){
		this->v = v;
		this->e = e;
		edges = vector<vector<pair<int,int> > >(v+1,vector<pair<int,int> >());
	}
	void addEdge(int u, int v, int w);
};

void graph::addEdge(int u, int v, int w){
	edges[u].push_back(make_pair(v,w));
}

void relaxEdge(int u, int v, int w, int* parent, long long* dist){// Edge from u->v
	if(dist[v]> dist[u]+w){
		dist[v] = dist[u]+w;
		parent[v]=u;
	}
}

int main(){
	int nv, ne;
	cin>>nv>>ne;
	graph* g = new graph(nv,ne);
	for(int i=0; i<ne; i++){
		int u,v,w;
		cin>>u>>v>>w;
		g->addEdge(u,v,w);
	}
	int source;
	cin>>source;
	long long dist[nv+1];
	for(int i=0; i<=nv; i++){dist[i]=inf;}
	dist[source] = 0;
	int parent[nv+1];
	memset(parent, -1, sizeof(parent));
	for(int i=1; i<=nv-1; i++){
		for(int k=1; k<=nv; k++){
			for(int j=0; j<(g->edges)[k].size(); j++){
				relaxEdge(k, (g->edges)[k][j].first, (g->edges)[k][j].second, parent, dist);
			}
		}
	}
	for(int i=1; i<=nv; i++){
		cout<<dist[i]<<endl;
	}
	for(int i=1; i<=nv; i++){
		for(int j=0; j<(g->edges)[i].size(); j++){
			if(dist[(g->edges)[i][j].first] > dist[i] + (g->edges)[i][j].second){
				cout<<"Negitive cycle"<<endl;
			}
		}
	}
}