#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class box{
	int l,b,h;
public:
	box(int l, int b, int h){
		this->l = l;
		this->b = b;
		this->h = h;
	}
	bool operator<(const box & compBox) const{
		return ((l<compBox.l) || 
				((l==compBox.l)&&(b<compBox.b)) ||
				((l==compBox.l)&&(b==compBox.b)&&(h<compBox.h)));
	}
	friend bool isCompletelyLess(box&, box&);
};


bool isCompletelyLess(box &a, box &b){
	return (a.l<=b.l)&&(a.b<=b.b)&&(a.h<=b.h);
}


class boxStack{
	vector<box> boxes;
public:
	void insert(box b){
		boxes.push_back(b);
	}
	int maxStack(){
		sort(boxes.rbegin(), boxes.rend());
		vector<int> count(boxes.size(),1);
		for(int i=1; i<count.size(); i++){
			for(int j=0; j<i; j++){
				if(isCompletelyLess(boxes[i], boxes[j])){
					count[i] = max(count[i], count[j] + 1);
				}
			}
		}
		return *max_element(count.begin(), count.end());
	}
};

int main(){
	boxStack a;
	a.insert(box(1,1,1));	
	a.insert(box(2,2,2));	
	a.insert(box(3,3,3));
	cout << a.maxStack() <<endl;
}