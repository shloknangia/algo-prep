#include<iostream>
#include<queue>
using namespace std;

int main() {
	
	queue<int> q;
	 for(int i=0;i<10;i++){
    	q.push(i);
	}

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	
	//doubly ended
	//push front,pop_back,pop_front,push_back
    
    return 0;    
}

