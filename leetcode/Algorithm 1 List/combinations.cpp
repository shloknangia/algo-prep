#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 7. Combinations
// Medium

// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]

 

// Constraints:

//     1 <= n <= 20
//     1 <= k <= n


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        set<vector<int>> res;
        vector<vector<int>> res_v;
        
        vector<int> comb = {};
        findCombination(k , 1, n, comb, res);
        // print(res);
        
        for(auto v: res){
            res_v.push_back(v);
        }
        
        return res_v;
    }
    
    void print(set<vector<int>> v){
        for(auto a: v){
            for(auto b:a){
                cout<<b<<" ,";
            }
            cout<<endl;
        }
    }
    
    void findCombination(int k, int s, int e, vector<int>& combination, set<vector<int>>& result){
        if(combination.size() == k) {
            vector<int> temp = combination;
            // sort(temp.begin(), temp.end());
            result.insert(temp);
            return;
        }
        if(s>e) return;
        
        // dont take s
        findCombination(k, s, e-1, combination, result);
        
        // take s
        combination.push_back(e);
        findCombination(k, s, e-1, combination, result);
        combination.pop_back();
        
    }
};




int main(){


    return 0;
};