#include<iostream>
#include "queue.h"
using namespace std;

int main(){

    Queue<int> q;

    for(int i=0;i<7;i++){
        q.push(i);
    }
    q.pop();
    q.push(8);

    while(!q.isEmpty()){

        cout<< q.front();
        q.pop();
    }

return 0;
}
