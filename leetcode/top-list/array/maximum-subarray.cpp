#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// 53. Maximum Subarray
// Easy

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Example 2:

// Input: nums = [1]
// Output: 1

// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23

 

// Constraints:

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = INT_MIN;
        int cs = 0;
        int n = nums.size();
        int max_num = INT_MIN;
        bool allNeg = true;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>0) allNeg = false;
            max_num = max(max_num, nums[i]);
            cs += nums[i];
            cs = max(cs, 0);
                
            sum = max(sum,cs);
        }
        
        return allNeg?max_num: sum;
        
    }
};


int main(){


    return 0;
};