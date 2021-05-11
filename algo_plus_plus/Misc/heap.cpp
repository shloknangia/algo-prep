#include<iostream>
#include"heap.h"
using namespace std;

int main(){
	Heap h(true);
	int a[] = {7,6,4,3,1,2,9,10,15}
	for(int i=1;i<=10;i++){
		h.push(i);
	}
	while(h.isEmpty()){
		cout<<h.gettop()<<" ";
		h.pop();
	}
	return 0;
}
