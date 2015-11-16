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

pair<int,int> maxPal(string s){
	int length = s.size();
	int pal[length+1];
	for(int i=0; i<=length; i++){
		pal[i] = 1;
	}
	pal[1] = 1;
	int index = 2, nextPtr = 3, prevPtr = 1;
	
	while(index<=length){
		while(prevPtr>=1 && nextPtr<=length && s[prevPtr-1]==s[nextPtr-1]){
			pal[index] = nextPtr - prevPtr + 1;
			nextPtr++;
			prevPtr--;
		}
		if(nextPtr==length+1){break;}
		int possIndex = index + 1;
		bool found = false;
		while(possIndex<nextPtr){
			int palAroundThis = pal[index - (possIndex - index)];
			if(possIndex + palAroundThis/2 == nextPtr-1){
				index = possIndex;
				prevPtr = possIndex - (nextPtr - possIndex);
				found = true;
				break;
			}
			possIndex++;
		}
		if(!found){
			index = nextPtr;
			nextPtr = nextPtr + 1;
			prevPtr = index - 1;
		}
	}

	int maxVal = 0, maxIndex = 0;
	for(int i=1; i<=length; i++){
		if(pal[i]>maxVal){
			maxVal = pal[i];
			maxIndex = i-1;
		}
	}
	return make_pair(maxVal,maxIndex);
}


int main(){
	string given = "a";
	string s = "$";
	for(int i=0; i<given.size(); i++){
		s += given[i];
		s += '$';
	}
	pair<int,int> returnVal = maxPal(s);
	string out = "";
	int length = returnVal.first;
	int position = returnVal.second;
	for(int i = position - length/2 + 1; i<=position + length/2; i+=2)
		out += s[i];
	cout<< out <<endl;
}