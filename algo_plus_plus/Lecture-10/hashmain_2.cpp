#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){

    hashTable<int> h;

    h.insert("mango",100);
    cout<< h["mango"];
    h["apple"] = 200;
    cout<<h["apple"]<<endl;
    //h["mango"] = 100;

return 0;
}


