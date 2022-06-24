#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 238. Product of Array Except Self
// Medium

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

 

// Constraints:

//     2 <= nums.length <= 105
//     -30 <= nums[i] <= 30
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res(nums.size(), 1);
        
        int prod = 1;
        for(int i=0;i<nums.size();i++){
            prod *= nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                res[i] = prod/nums[i];
            }
            else{
                res[i] = getProdWithout(i, nums);
            }
        }
        return res;
        
    }
    
    int getProdWithout(int index, vector<int> n){
        int prod = 1;
        
        for(int i=0;i<n.size();i++){
            if(i != index) prod *= n[i];
        }
        return prod;
    }
};




int main(){


    return 0;
};