// Headers
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

struct node{
	int val;
	node* left;
	node* right;
	node(){
		left = right = NULL;
	}
	node(int val){
		this->val = val;
		left = right = NULL;
	}
};

int val1, val2;


// My method - Sollu 

// node* LCA(bool &firstBool, bool &secondBool, node* root){ 
// 	if(root==NULL){
// 		return NULL;
// 	}

// 	bool firstBoolCopy = firstBool, secondBoolCopy = secondBool;
// 	node* temp = LCA(firstBoolCopy, secondBoolCopy, root->left);
// 	if(temp!=NULL){
// 		return temp;
// 	}

// 	bool firstBoolCopy2 = firstBool, secondBoolCopy2 = secondBool;
// 	temp = LCA(firstBoolCopy2,secondBoolCopy2,root->right);
// 	if(temp!=NULL){
// 		return temp;
// 	}

// 	firstBool = firstBoolCopy || firstBoolCopy2;
// 	secondBool = secondBoolCopy || secondBoolCopy2;
// 	if(root->val == val1){
// 		firstBool = true;
// 	}
// 	if(root->val == val2){
// 		secondBool = true;
// 	}
// 	if(firstBool && secondBool){
// 		return root;
// 	}
// 	else{
// 		return NULL;
// 	}
// }


// Awesome method

node* lcaHelper(int val1, int val2, bool &b1, bool &b2, node* root){
	if(root==NULL){
		return NULL;
	}
	if(root->val==val1){
		b1=true;
		return root;
	}
	if(root->val==val2){
		b2=true;
		return root;
	}
	node* lcaLeft = lcaHelper(val1,val2,b1,b2,root->left);
	node* lcaRight = lcaHelper(val1,val2,b1,b2,root->right);
	if(lcaLeft!=NULL && lcaRight!=NULL){
		return root;
	}
	if(lcaLeft!=NULL){
		return lcaLeft;
	}
	else{
		return lcaRight;
	}
}

bool find(node* root, int val){
	if(root==NULL){
		return false;
	}
	if(root->val == val){
		return true;
	}
	return (find(root->left,val) || find(root->right,val));
}

node* lca(int val1, int val2, bool &b1, bool &b2, node* root){
	node* temp = lcaHelper(val1, val2, b1, b2, root);
	if(b1&&b2 || b1&&find(temp,val2) || b2&&find(temp,val1)){
		return temp;
	}
	return NULL;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	while(true){
		cin>> val1 >> val2;
		bool isPresent1 = false, isPresent2 = false;
		node* temp = lca(val1, val2, isPresent1, isPresent2, root);
		if(temp!=NULL){
			cout<< temp->val <<endl;
		}
		else{
			cout<< "Not dounf" <<endl;
		}
	}
}