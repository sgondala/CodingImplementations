#include <bits/stdc++.h>
using namespace std;

int getKth(int a[], int b[], int m, int n, int k){
	assert(k<= m+n);
	int i = (double)m/(m+n) * (k-1);
	int j = k - i - 1;
	int ai = a[i];
	int bj = b[j];
	int aiPrev = (i==0)? INT_MIN : a[i-1];
	int bjPrev = (j==0)? INT_MIN : b[j-1];
	if(ai>=bjPrev && ai <= bj){
		return ai;
	}
	else if (bj>=aiPrev && bj<=ai){
		return bj;
	}
	if(ai < bjPrev){
		return getKth(a+i+1,b,m-i-1,j+1,k-i-1);
	}
	else{
		return getKth(a,b+j+1,i+1,n-j-1,k-j-1);
	}
}

int main(){
	int a[] = {1,3,5,7,9};
	int b[] = {2,4,6,8,10};
	for(int i=1; i<=10; i++)
		cout << getKth(a,b,5,5,i) <<endl;
}