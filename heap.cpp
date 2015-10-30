#include <iostream>
#include <vector>
using namespace std;

int left(int val){
	return 2*val;
}

int right(int val){
	return 2*val + 1;
}

int parent(int val){
	return val/2;
}

void makeHeap(int a[], int index, int heapSize){// Talking About MaxHeaps only!!
	int leftIndex = left(index);
	int rightIndex = right(index);
	int largestIndex = index;
	int largestValue = a[index];
	if(leftIndex<=heapSize && a[leftIndex]>largestValue){
		largestIndex = leftIndex;
		largestValue = a[leftIndex];
	}
	if(rightIndex<=heapSize && a[rightIndex]>largestValue){
		largestIndex = rightIndex;
		largestValue = a[rightIndex]; 
	}
	if(largestIndex!=index){
		swap(a[index], a[largestIndex]);
		makeHeap(a, largestIndex, heapSize);
	}
	return;
}

void buildHeap(int a[], int heapSize){
	for(int i=heapSize/2; i>=1; i--){ //This is becz, always n/2 + 1 till heapSize are leaves!!!
		makeHeap(a, i, heapSize);
	}
}

void heapSort(int a[], int heapSize){ //We use maxHeaps for heapSort... Not min heapp!!!!!
	buildHeap(a, heapSize);
	while(heapSize!=1){
		swap(a[1], a[heapSize]);
		heapSize--;
		makeHeap(a, 1, heapSize);
	}
}

void increaseKeyValue(int a[], int index, int newVal){
	if(a[index]>=newVal){
		cout<<"Give correct key value" <<endl;
		return;
	}
	a[index] = newVal;
	while(index>1 && a[parent(index)]<a[index]){
		swap(a[index], a[parent(index)]);
		index = parent(index);
	}
}

int extractMax(int a[], int &heapSize){
	int returnVal = a[1];
	swap(a[1],a[heapSize]);
	heapSize--;
	makeHeap(a, 1, heapSize);
	return returnVal;
} 

void addVal(int a[], int val, int &heapSize){
	heapSize++;
	a[heapSize] = -100000000;
	increaseKeyValue(a, heapSize, val);
}

int main(){
	int a[] = {10,1,3,4,2,5,6,7,8,9};
	int heapSize = 5; //Heap starts at 1 always - So 1,2,3,4,5
	buildHeap(a,heapSize);
	heapSort(a,heapSize);
	extractMax(a,heapSize);
	addVal(a,6,heapSize);
}