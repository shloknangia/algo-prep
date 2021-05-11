#include<iostream>
#include<queue>

using namespace std;


int main(){
	priority_queue<int> pq;
	int a[] = {7,6,4,3,1,2,9,10,15};
	for(int i=0;i<9;i++){
		pq.push(a[i]);
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
