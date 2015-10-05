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

node* LCA(bool &firstBool, bool &secondBool, node* root){ 
	if(root==NULL){
		return NULL;
	}

	bool firstBoolCopy = firstBool, secondBoolCopy = secondBool;
	node* temp = LCA(firstBoolCopy, secondBoolCopy, root->left);
	if(temp!=NULL){
		return temp;
	}

	bool firstBoolCopy2 = firstBool, secondBoolCopy2 = secondBool;
	temp = LCA(firstBoolCopy2,secondBoolCopy2,root->right);
	if(temp!=NULL){
		return temp;
	}

	firstBool = firstBoolCopy || firstBoolCopy2;
	secondBool = secondBoolCopy || secondBoolCopy2;
	if(root->val == val1){
		firstBool = true;
	}
	if(root->val == val2){
		secondBool = true;
	}
	if(firstBool && secondBool){
		return root;
	}
	else{
		return NULL;
	}
}

void inOrder(node* root){
	if(root==NULL){return;}
	inOrder(root->left);
	cout<< root->val <<" ";
	inOrder(root->right);
	return;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	inOrder(root);
	cout<<endl;
	while(true){
		cin>> val1 >> val2;
		bool isPresent1 = false, isPresent2 = false;
		node* temp = LCA(isPresent1, isPresent2, root);
		if(temp!=NULL){
			cout<< temp->val <<endl;
		}
		else{
			cout<< "Not dounf" <<endl;
		}
	}
}