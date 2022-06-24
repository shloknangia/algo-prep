#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 198. House Robber
// Medium

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

 

// Constraints:

//     1 <= nums.length <= 100
//     0 <= nums[i] <= 400


class Solution {
public:
    int rob(vector<int>& nums, int last = -2, int index = 0, int sum = 0) {
        // Recursion
        /*
            if(index >= nums.size()) return sum;

            if(last == index-1) return 0;

            // take
            int take = rob(nums, index, index+2, sum+nums[index]);

            //dontTake
            int dontTake = rob(nums, last, index+1, sum);

            return max(take, dontTake);
        */

        // DP
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2;i<nums.size();i++){
            for(int j=0;j<i-1;j++){
                dp[i] = max(dp[j]+nums[i], dp[i]);    
            }
            
        }
        int maxval = INT_MIN;
        
        for(int i = 0;i<nums.size();i++){
            cout<<dp[i]<<" ";
            maxval = max(dp[i], maxval);
        }
        return maxval;
        
    }
};



int main(){


    return 0;
};