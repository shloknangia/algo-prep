#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void query_print(priority_queue<int, vector<int> , greater<int> > pq){
    // print all elements of heap
    // we will empty it to traverse but as it is passed by value original will not be affected
    while(!pq.empty()){
        cout<<pq.top()<<", ";
        pq.pop();
    }
    cout<<endl;
}

int main(){

    // Find K largest elements in a running stream
    // running stream-> cannot store all the numbers
    // Use heap with less complexity
    // Ans: Not Max heap but min heap
    // Min heap of size 3
    // for every no. remove min element and add new(if max)
    // at end will be left with max 3 no.s
    // Complxity: N logK (better than N logN of sorting)

    priority_queue<int, vector<int> , greater<int> > pq;
    int cs = 0; // current size to ensure max limit on heap size

    // read running stream
    // use eof
    int no, k = 3;
    while(scanf("%d", &no)!= EOF){ // this will keep receiving no., no size needed
        // cout<<no<<endl;

        // give output(max K) if -1 is received
        if(no == -1){
            query_print(pq);
        }
        else if(cs<k){ //push if pq not full till k
            pq.push(no);
            cs++;
        }
        else{
            if(no > pq.top()){ // if full and new no is big , replace
                pq.pop(); // pop min number
                pq.push(no); // add new big no.
            }
        }
    }
    return 0;
}