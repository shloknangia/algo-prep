#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 377. Combination Sum IV
// Medium

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

// Example 2:

// Input: nums = [9], target = 3
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 1000
//     All the elements of nums are unique.
//     1 <= target <= 1000

 

// Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // cout<<target<<endl;
        /*
        if(target<0) return 0;
        if(target == 0) return 1;
        // if(i==nums.size()) return 0;
        int res = 0;
        //take + dont take
        for(int j = 0;j<nums.size();j++)
            res +=  combinationSum4(nums, target - nums[j]);
        return res;
        */
        
        vector<uint> dp (target+1, 0); // uint for unsigned int to hadle -ve values also
        // 1  2  3  4            [1,2,3]
        // 1 - (1) --1
        // 2 - (1,1)(2) -- 2
        // 3 - (1,1,1)(2,1)(1,2)(3) -- 4 -- sum of (i-nums(j))
           
        
        dp[0] = 1;
        // for(auto a:dp) cout<<a<<endl;
        
        
        for(int i=1;i<=target;i++){
            // int resi =0;
            dp[i] = 0;
            // cout<<i<<"-> ";
            for(auto n:nums){
                
                if(i-n>=0){
                    // cout<<"("<<n<<" -"<<dp[i-n]<<"), ";    
                    dp[i] += dp[i-n];
                }
                    
            }
            cout<<endl;
        }
        
        return dp[target];
    }
};


int main(){


    return 0;
};