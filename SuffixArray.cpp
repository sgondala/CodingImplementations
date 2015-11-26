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

struct helperTuple{
	int stringIndex;
	int prevRank;
	int nextRank;
};

bool compare(helperTuple a, helperTuple b){
	if(a.prevRank==b.prevRank){
		return a.nextRank < b.nextRank;
	}
	return a.prevRank<b.prevRank;
}

int main(){

	//Suffix array part
	string s = "banana";
	int suffixArray[s.size()][10];
	for(int i=0; i<s.size(); i++){
		suffixArray[i][0] = s[i]-'a';
	}
	int iterations = 1;
	helperTuple all[s.size()];
	
	for(int count = 1; count < s.size(); count *=2){
		
		for(int i=0; i<s.size(); i++){
			all[i].prevRank = suffixArray[i][iterations - 1];
			if(i+count<s.size()){
				all[i].nextRank = suffixArray[i+count][iterations - 1];
			}
			else{
				all[i].nextRank = -1;
			}
			all[i].stringIndex = i;
		}

		
		sort(all, all+s.size(), compare);
		suffixArray[all[0].stringIndex][iterations] = 0;
		
		int currRank = 0;
		for(int i=1; i<s.size(); i++){
			if(all[i-1].prevRank!=all[i].prevRank || all[i-1].nextRank!=all[i].nextRank){
				currRank++;
			}
			suffixArray[all[i].stringIndex][iterations] = currRank;

		}
		iterations++;
	}

	sort(all, all+s.size(), compare);
	
	int suffixRanks[s.size()];
	for(int i=0; i<s.size(); i++){
		suffixRanks[i] = all[i].stringIndex;
	}

	//LCP array part
	int rank[s.size()];
	for(int i=0; i<s.size(); i++){
		rank[suffixRanks[i]] = i;
	}

	int lcp[s.size()];
	int k = 0;
	for(int i=0; i<s.size(); i++){
		if(rank[i]==s.size()-1){k = 0; continue;}
		int j = suffixRanks[rank[i]+1];
		while(i+k<s.size() && j+k<s.size() && s[i+k]==s[j+k]){
			k++;
		}
		lcp[rank[i]] = k;
		if(k!=0){
			k--;
		}
	}

	int count = s.size() - suffixRanks[0];
	for(int i=1; i<s.size(); i++){
		count += s.size() - suffixRanks[i] - lcp[i-1];
	}
	cout << count <<endl;

}