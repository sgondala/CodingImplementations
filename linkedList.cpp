#include <bits/stdc++.h>
using namespace std;


struct node{
	node* next;
	node* prev;
	int val;
	node(){
		next=prev=NULL;
		val=0;
	}
	node(int a){
		next=prev=NULL;
		val=a;
	}
};

struct llist{
	node* head;
	llist(){
		head = NULL;
	}
	void print();
	void insert(int newVal);
	void deleteInt(int deleteVal);
	node* search(int searchVal);
};

void llist::print(){
	node* temp = head;
	while(temp){
		cout<< temp->val << " ";
		temp = temp->next;
	}
	return;
}

void llist::insert(int newVal){
	node* temp = new node(newVal);
	if(head){head->prev = temp;}
	temp->next = head;
	head = temp;
	return;
}

node* llist::search(int searchVal){
	node* temp = head;
	while(temp && (temp->val!=searchVal)){
		temp = temp->next;
	}
	return temp;
}

void llist::deleteInt(int deleteVal){
	node* temp = search(deleteVal);
	if(temp){
		if(temp->next){temp->next->prev = temp->prev;}
		if(temp->prev){temp->prev->next = temp->next;}
		else{
			head = temp->next;
			head->prev = NULL;
		}
	}
}

int main(){
	llist a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.print();
	cout<<endl;
	a.deleteInt(2);
	a.print();
	cout<<endl;
	a.deleteInt(1);
	a.print();
	a.insert(2);
	cout<<endl;
	a.deleteInt(3);
	a.print();
	cout<<endl;
}










