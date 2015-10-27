// Headers
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

#define trace1(x)							cerr << #x << ": " << x << endl;
#define trace2(x, y)						cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)						cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) 			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<pp> > edges(v, vector<pp>());
	for(int i=0; i<e; i++){
		int start, end, weight; //Assuming starts from 0
		cin>>start>>end>>weight;
		edges[start].pb(mp(end,weight));
		edges[end].pb(mp(start,weight));
	}

	vector<int> distances(v,100000000);
	vector<int> parent(v,-1);
	set<pp> all;
	distances[0] = 0;
	for(int i=0; i<v; i++){
		all.insert(mp(distances[i],i));
	}

	while(!all.empty()){
		pp temp = *(all.begin());
		all.erase(all.begin());
		int node = temp.second;
		for(int i=0; i<edges[node].size(); i++){
			int currentNodeIndex = edges[node][i].first;
			int edgeLength = edges[node][i].second;
			if(edgeLength < distances[currentNodeIndex]){
				set<pp>::iterator it = all.find(mp(distances[currentNodeIndex],currentNodeIndex));
				all.erase(it);
				distances[currentNodeIndex] = edgeLength;
				parent[currentNodeIndex] = node;
				all.insert(mp(distances[currentNodeIndex],currentNodeIndex));
			}
		}
	}

	int sum = 0;
	for(int i=0; i<v; i++){
		sum += distances[i];
	}
	cout<< sum <<endl;
}
