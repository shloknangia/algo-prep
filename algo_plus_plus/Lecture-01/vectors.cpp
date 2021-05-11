#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int main(){
    ///Vector is resizeable array, ADT defined in C++ STL

    vector<int> v;
    v.reserve(10);
    cout<<v.capacity()<<endl;

    for(int i=0;i<12;i++){
        v.push_back(10-i);
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"max"<<*max_element(v.begin(), v.end());
    // *max;
    cout<<endl;
    cout<<v.capacity()<<endl;

return 0;
}
