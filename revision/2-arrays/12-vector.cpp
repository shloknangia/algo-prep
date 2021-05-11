#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Vectors
    // C++ STL
    // resizable arrays, arrays have fixed size
    // doubles size to add more elements
    // Use Dynamic memory
    // can be accesed as arrays
    // header: <vector>

    vector<int> v;
    // declare initilize
    // vector<int> v (10, 0); // size, initial value
    // 2D- NxN vector matrix, all initilized by 0
    // vector<vector<int>> b (N, vector<int> (N, 0));


    v.reserve(100);// will reserve atlease 100 buckets, resize after 100
    int n;
    cin>>n;

    //  for v[i] = 10, if i does not exist it will give error
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp); // adds element at back of vector
    }

    v.pop_back(); // removes element from last

    // sort a vector, header: <algorithm>
    sort(v.begin(), v.end()); // can also add custom comparator

    for(int i=0;i<v.size();i++){ // v.size() returns no of elements
        cout<<v[i]<<endl;
    }

    // v.clear();// to clean or empty    
    // v.capacity(); // max capacity till now
    // v.max_size();// max memory a vector can take in your system
	return 0;
}


