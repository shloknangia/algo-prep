// Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

// You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

// Example

// For

// a = [[1, 2, 3],
//      [4, 5, 6],
//      [7, 8, 9]]

// the output should be

// rotateImage(a) =
//     [[7, 4, 1],
//      [8, 5, 2],
//      [9, 6, 3]]

#include<bits/stdc++.h>
using namespace std;


// reverse all columns
void revcols(vector<vector<int>> &a){
    for(int i=0;i<a.size()/2;i++){
        for(int j=0;j<a[i].size();j++){
            swap(a[i][j], a[a.size()-1-i][j]);
        }
    }
}
// swap all but diagonal ie. all rows , col from i to n
void swapllButDiag(vector<vector<int>> &a){
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a[i].size();j++){
            swap(a[i][j], a[j][i]);
        }
    }
}


vector<vector<int>> rotateImage(vector<vector<int>> a) {

    // WITH EXTRA MEMORY

    // vector<vector<int>> b (a.size(), vector<int> (a.size(), 0));
    // for(int i=0;i<a.size();i++){
    //     for(int j=0;j<a[i].size();j++){
    //         // swap(a[i][j], a[j][a.size() -i-1]);
    //         // b[i][j]= a[j][a.size() -i-1];
    //         b[j][a.size() -i-1] = a[i][j];
    //     }
    // }
    // return b;

    // WITHOUT EXTRA MEMORY
    
    revcols(a);
    swapllButDiag(a);
    return a;
}


// 00 -> 0n
// 01 -> 1, n
// 0, n -> n , n

//1,0 -> 0, 1
// 1,1 -> 1.1
//1,2 -> 2,1
//1,n -> n, 1

//2, 0 -> 0,0,
//2, 1-> 1, 0
//2,2 -> 2, 0
//2, n, n,0


