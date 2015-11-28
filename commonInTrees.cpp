// Headers
#include <bits/stdc++.h>
#include "minPriorityQueue.cpp"
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

struct node{
	int val;
	node* left, *right;
	node(int _val){
		val = _val;
		left = right = NULL;
	}
};

//Same method for all double inorder traversals at same time
// Simple for single one - Lot of intricacies if doing 2 at a time!!
void printCommon(node* r1, node* r2){
	stack<node*> s1,s2;
	while(true){
		if(r1){
			s1.push(r1);
			r1 = r1->left;
		}
		else if(r2){
			s2.push(r2);
			r2 = r2->left;
		}
		else if(!s1.empty() && !s2.empty()){
			r1 = s1.top();
			r2 = s2.top();
			if(r1->val == r2->val){
				cout<< (r1->val)<< " ";
				r1 = r1->right;
				r2 = r2->right;
				s1.pop();
				s2.pop();
			}
			else if(r1->val < r2->val){
				r1 = r1->right;
				r2 = NULL;
			}
			else{
				r2 = r2->right;
				r1 = NULL;
			}
		}
		else{
			break;
		}
	}
}


void print(node* r){
	if(r!=NULL){
		print(r->left);
		cout<< (r->val) <<" ";
		print(r->right);
	}
}

int main(){
	node* r1 = new node(4);
	r1->left = new node(2);
	r1->left->left = new node(1);
	r1->left->right = new node(3);
	r1->right = new node(5);

	node* r2 = new node(3);
	r2->left = new node(2);
	r2->right = new node(5);

	printCommon(r1,r2);
	cout<<endl;
}