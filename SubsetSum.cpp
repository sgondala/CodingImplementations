#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int index, int a[], int sum, int isPresent[]){
	sum -= a[index];
	if(sum==0) return true;
	if(sum<0) return false;
	for(int j=index+1; j<4; j++){
		isPresent[j] = 1;
		if(subsetSum(j,a,sum, isPresent)) return true;
		isPresent[j] = 0;
	}
	return false;
}


int main(){
	int a[] = {2,3,4,5};
	int sum  = 14;
	int isPresent[] = {0,0,0,0} ;
	for(int i=0; i<4; i++){
		isPresent[i] = 1;
		if(subsetSum(i,a,sum, isPresent)) {
			cout<<"YES"<<endl; 
			for(int j=0; j<4; j++){ cout<<isPresent[j] <<endl;};
			return 0;
		}
		isPresent[i] = 0;
	}
	cout<<"NO"<<endl;

}