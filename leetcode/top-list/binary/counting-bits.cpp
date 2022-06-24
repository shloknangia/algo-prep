#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 338. Counting Bits
// Easy

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

 

// Constraints:

//     0 <= n <= 105

 

// Follow up:

//     It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
//     Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            ans.push_back(countOnes(i));
        }
        return ans;
        
        
        //memoization
        // vector<int> ret(num+1, 0);
        // for (int i = 1; i <= num; ++i)
        //     ret[i] = ret[i&(i-1)] + 1; // removes last bit
        // return ret;
        
        
    }
    
    // O(logN)
    int countOnes(int i){
        int count =0;
        while(i){
            i = i&(i-1);
            count++;
        }
        return count;
    }
    
};



int main(){


    return 0;
};