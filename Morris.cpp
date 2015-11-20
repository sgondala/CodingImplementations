#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* left, *right;
	node(int _val){
		val = _val;
		left = right = NULL;
	}
};

void morris(node* root){
	node* current = root;
	while(current!=NULL){
		if(current->left!=NULL){
			node* preNode = current->left;
			node* preNodeRight = preNode;
			while(preNodeRight->right && preNodeRight->right!=current){
				preNodeRight = preNodeRight->right;
			}
			if(preNodeRight->right == NULL){
				preNodeRight->right = current;
				current = preNode; 
			}
			else{
				preNodeRight->right = NULL;
				cout<< current->val <<" ";
				current = current->right;
			}
		}
		else{
			cout<< current->val <<" ";
			current = current->right;
		}
	}
	cout<<endl;
}

int main(){
	node* root = new node(4);
	root->left = new node(2);
	root->left->left = new node(1);
	root->left->right = new node(3);
	root->right = new node(6);
	root->right->left = new node(5);
	root->right->right = new node(7);
	morris(root);
}