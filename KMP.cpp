#include <bits/stdc++.h>
using namespace std;

void fillLcp(string pattern, int lcp[]){
	lcp[0] = 0;
	int j = 0;
	for(int i=1; i<pattern.size(); i++){
		while(j>0 && pattern[j]!=pattern[i]){
			j = lcp[j-1];
		}
		if(pattern[j]==pattern[i]){
			j++;
		}
		lcp[i] = j;
	}
}

void searchForPattern(string text, string pattern, int lcp[]){
	int j=0;
	for(int i=0; i<text.size(); i++){
		while(j>0 && pattern[j]!=text[i]){
			j = lcp[j-1];
		}
		if(text[i]==pattern[j]){
			j++;
			if(j==pattern.size()-1){
				cout<<"Match at "<< i-j+1 <<endl;
				j = lcp[j-1];
			}
		}
	}
}

int main(){
	string text,pattern;
	cin>>text>>pattern;
	int lcp[pattern.size()];
	fillLcp(pattern,lcp);
	searchForPattern(text,pattern,lcp);
	cout<<endl;
}