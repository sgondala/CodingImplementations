// Headers
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

//GCD of 2 int's
int gcd(int a, int b){
	if(b==0){return a;}
	if(a<b){return gcd(b,a);}
	return gcd(b,a%b);
}

// Prime numbers by seive - O(n loglogn) - Arithematic operations
// All primes till 1000000
vector<bool> isPrime(1000000, true);

void seive(){
	isPrime[1] = false;
	for(int i=2; i<1000000/2; i++){
		if(!isPrime[i]){continue;}
		for(int j=2; i*j<1000000; j++){
			isPrime[i*j] = false;
		}
	}
}

// Alkwaratz(?) exponentiation

long long power(long long base, int exp){
	if(exp==0){return 1;}
	long long temp = power(base, exp/2);
	temp = (temp*temp)%mod;
	if(exp%2==0){return temp;}
	else{return (temp*base)%mod;}
}


// ncr of numbers % mod

#define mod 1000000007

long long fac[100005], ifac[100005];

void fillfac(){
	fac[0] = fac[1] = 1;
	for(long long i=2; i<100005; i++){
		fac[i] = (fac[i-1] * i)%mod;
	}
}

void fillifac(){
	ifac[0] = ifac[1] = 1;
	for(long long i=2; i<100005; i++){
		ifac[i] = (ifac[i-1] * power(i,mod-2))%mod;
	}
}

long long ncr(long long n, long long r){
	long long temp;
	temp = fac[n];
	temp = (temp*ifac[n-r])%mod;
	temp = (temp*ifac[r])%mod;
	return temp;
}
