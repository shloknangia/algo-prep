#include<iostream>
#include "heap.h"
using namespace std;


int main(){

    Heap h(false);
    int a[] = {7,6,5,4,3,1,2,9,10,15};
    for(int i=0;i<10;i++){
        h.push(a[i]);
    }

    while(!h.isEmpty()){
        cout<< h.getTop()<<" ";
        h.pop();
    }

}
