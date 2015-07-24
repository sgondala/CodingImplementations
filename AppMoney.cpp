#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> money;
	int total = 0;
	int people = 0;
	while(true){
		int temp;
		cin>>temp;
		if(temp!=-1){ total+= temp; people +=1; money.push_back(temp);}
		else{break;}
	}
	int avg = total/people;
	
	vector<pair<int,int> > aboveAvg;
	vector<pair<int,int> > belowAvg;
	for(int i=0; i<money.size(); i++){
		if(money[i]>avg){aboveAvg.push_back(make_pair(money[i]-avg,i));}
		else if(money[i]<avg){belowAvg.push_back(make_pair(avg-money[i],i));}
	}
	sort(aboveAvg.rbegin(), aboveAvg.rend());
	sort(belowAvg.rbegin(), belowAvg.rend());
	int aboveAvgPtr = 0, belowAvgPtr = 0;

	vector<vector<pair<int, int> > > transactions(people, vector<pair<int, int> >()); //position, money
	
	while((aboveAvgPtr != aboveAvg.size()) &&  (belowAvgPtr != belowAvg.size())){
		if(aboveAvg[aboveAvgPtr].first >= belowAvg[belowAvgPtr].first){
			bool isEqual= false;
			if(aboveAvg[aboveAvgPtr].first == belowAvg[belowAvgPtr].first) {isEqual = true;}
			aboveAvg[aboveAvgPtr].first -= belowAvg[belowAvgPtr].first;
			transactions[aboveAvg[aboveAvgPtr].second].
				push_back(make_pair(belowAvg[belowAvgPtr].second, belowAvg[belowAvgPtr].first));
			if(isEqual) {aboveAvgPtr++;}
			belowAvgPtr ++;
		}
		else{
			belowAvg[belowAvgPtr].first -= aboveAvg[aboveAvgPtr].first;
			transactions[aboveAvg[aboveAvgPtr].second].
				push_back(make_pair(belowAvg[belowAvgPtr].second, aboveAvg[aboveAvgPtr].first));
			aboveAvgPtr ++;
		}
	}

	for(int i=0; i<transactions.size(); i++){
		if(transactions[i].size() !=0) {
			cout<<i+1<<endl;
			for(int j=0; j<transactions[i].size(); j++){
				cout<<transactions[i][j].first+1<<" "<<transactions[i][j].second<<endl;
			}
		}
	}

}