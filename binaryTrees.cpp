#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(){
		left=right=NULL;
	};
	node(int val){
		this->val = val;
		left=right=NULL;
	}
};

struct bTree{
	node* root;
	void insert(int val);
	node* search(int val);
	void deleteVal(int val);
	node* findParentForNode(int val);
	bTree(){
		root = NULL;
	}
	bTree(int val){root = new node(val);}
};

void bTree::insert(int val){
	if(!root){
		root = new node(val);
		return;
	}
	node* temp = root;
	node* parent = root;
	while(temp){
		parent = temp;
		if(val >= temp->val){temp = temp->right;}
		else{ temp = temp->left;} 
	}
	if(val >= parent->val){parent->right = new node(val);}
	else{parent->left = new node(val);}
	return;
}

void inorderPrint(node* root){
	node* temp = root;
	if(temp){
		inorderPrint(temp->left);
		cout<< temp->val <<endl;
		inorderPrint(temp->right);
	}
	return;
}

node* bTree::search(int val){
	node* temp = root;
	while(temp && (temp->val!=val)){
		if(val > temp->val){temp = temp->right;}
		else if(val < temp->val){temp = temp-> left;}
	}
	return temp;
}

node* bTree::findParentForNode(int val){
	if(!root || (root->val == val)){return NULL;}
	node* temp = root;
	node* parent = NULL;
	while(temp){
		if(temp->val == val) return parent;
		if(val < temp->val) {parent = temp; temp= temp->left;}
		if(val > temp->val) {parent = temp; temp= temp->right;}
	}
	return NULL;
}


void bTree::deleteVal(int val){
	node* temp = search(val);
	if(!temp){return;}
	if(!(temp->left) && !(temp->right)){
		if(temp==root){
			root = NULL;
			delete temp;
		}
		else{
			node* parent = findParentForNode(val);
			if(parent->right==temp){parent->right=NULL; delete temp;}
			else{parent->left=NULL; delete temp;}
		}
	}
	else if(!(temp->left) && (temp->right)){
		if(temp==root){
			root = root->right;
			delete temp;
		}
		else{
			node* parent = findParentForNode(val);
			if(parent->right==temp){parent->right=temp->right; delete temp;}
			else{parent->left = temp->right; delete temp;}
		}
	}
	else if((temp->left) && !(temp->right)){
		if(temp==root){
			root = root->left;
			delete temp;
		}
		else{
			node* parent = findParentForNode(val);
			if(parent->right==temp){parent->right = temp->left; delete temp;}
			else{parent->left = temp->left; delete temp;}
		}
	}
	else{
		node* minNode =temp->right;
		while(minNode->left){
			minNode = minNode->left;
		}
		int valStoring = minNode->val;
		deleteVal(minNode->val);
		temp->val = valStoring;
	}
	cout<<"Delete Done \n";
	return;
}

int main(){
	bTree a;
}