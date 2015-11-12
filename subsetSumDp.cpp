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

template <class T>

void print2dVec(T a){
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); i++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	int a[] = {3,-1};
	int n = sizeof(a)/sizeof(a[0]);
	int maxNeg = 0, maxPos = 0;
	for(int i=0; i<n; i++){
		if(a[i]<=0){
			maxNeg += a[i];
		}
		else{
			maxPos += a[i];
		}
	}
	maxNeg *= -1;
	bool dp[n][maxNeg+maxPos+1];
	memset(dp, false, sizeof(dp));
	
	for(int i=0; i<n; i++){
		for(int sum = -maxNeg; sum<=maxPos; sum++){
			if(a[i]==sum){
				dp[i][sum+maxNeg] = true;
			}
			if(i!=0){
				dp[i][sum+maxNeg] = dp[i][sum+maxNeg] || dp[i-1][sum+maxNeg];
				// trace4(i,sum,dp[i-1][sum],dp[i][sum]);
				if(sum-a[i]+maxNeg>=0 && sum-a[i]+maxNeg<=maxNeg+maxPos){
					dp[i][sum+maxNeg] = dp[i][sum+maxNeg] || dp[i-1][sum-a[i]+maxNeg];
				}
			}
		}
	}
	
	cout << dp[n-1][maxNeg] <<endl;
}