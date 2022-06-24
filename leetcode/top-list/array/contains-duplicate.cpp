#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// 217. Contains Duplicate
// Easy

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true

// Example 2:

// Input: nums = [1,2,3,4]
// Output: false

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

 

// Constraints:

//     1 <= nums.length <= 105
//     -109 <= nums[i] <= 109



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // O(N^2)
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;
        

        // O(N)
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                return true;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        return false;
        
    }
};



int main(){


    return 0;
};