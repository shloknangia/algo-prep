#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    // Heaps or priority queue - STL 
    // header: <queue>
    // name: priority_queue
    // .top(), .pop(), .push()

    priority_queue<int> pq; // by default it is max heap

    // for min heap
    priority_queue<int, vector<int>, greater<int> >  pq;  
    // need to use comparator as 3rd arg
    // inbuilt: greater<int> comparator
    // header: <functional>

    int a[10] = {5,6,17,18,9,11};

    for(int i =0;i<6;i++){
        pq.push(a[i]);
    }

    while(!pq.empty()){
        cout<<pq.top()<<", ";
        pq.pop();
    }

    return 0;
}