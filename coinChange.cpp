#include <bits/stdc++.h>
using namespace std;

int coinCount;
vector<int> coins;
int val;
vector<vector<int> > dp;

void filldp(){ //Assuming 1 is there at the end;
	for(int j=0; j<=val; j++){
		dp[0][j] = 0;
	}
	for(int i=0; i<=coinCount; i++){
		dp[i][0] = 1;
	}
	for(int i=1; i<=coinCount; i++){
		for(int j=1; j<=val; j++){
			dp[i][j] = dp[i-1][j];
			if(coins[i-1]<=j){
				dp[i][j] += dp[i][j-coins[i-1]];
			}
		}
	}
}

int main(){
	cin>>coinCount;
	coins = vector<int>(coinCount);
	for(int i=0; i<coinCount; i++){
		cin>>coins[i];
	}
	sort(coins.begin(), coins.end());
	cin>>val;
	dp = vector<vector<int> >(coinCount+1, vector<int>(val+1,0));
	filldp();
	cout<<dp[coinCount][val]<<endl;
}