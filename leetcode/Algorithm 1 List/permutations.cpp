#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 46. Permutations
// Medium

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

 

// Constraints:

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<vector<int>> res;
        findPermutation(nums, 0, s, nums.size());
        
        for(auto a: s){
            res.push_back(a);
        }
        return res;
    }
    
    
    void findPermutation(vector<int>& nums, int i, set<vector<int>>& s, int n){
        
        if(i == n)  
            s.insert(nums);
        
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            findPermutation(nums, i+1, s, n);
            swap(nums[i], nums[j]);
        }
        
    }
};



int main(){


    return 0;
};