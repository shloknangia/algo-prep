#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 300. Longest Increasing Subsequence
// Medium

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

 

// Constraints:

//     1 <= nums.length <= 2500
//     -104 <= nums[i] <= 104

 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?



class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        
        // Recursive approach
        /*
        // , int i = 0, int prev = INT_MIN) {
        if(i>=nums.size()) return 0; // cant pick any more elements
        
        int take = 0, dontTake = lengthOfLIS(nums, i+1, prev);           
        // try skipping the current element
        
        if(nums[i] > prev) take = 1 + lengthOfLIS(nums, i+1, nums[i]);   
        // or pick it if it is greater than previous picked element
        
        return max(take, dontTake);                                  
        // return whichever choice gives max LIS
        
        
        // return max(lengthOfLIS(nums, i+1, prev), (nums[i]>prev) + lengthOfLIS(nums, i+1, nums[i]));
        */

       
        
        
        // DP
        /*
        vector<int> lisarr (nums.size(), 0);
        // lisarr[i] is not LIS from 0->i
        // lisarr[i] is length longest LIS **[ending on i] (extra condition)
        // so that for lisarr[i+1], nums[i+1] can be appended to any of the nums[0->i](less than nums[i+1]) and form new LIS
        
        int prev = nums[0];
        lisarr[0] = 1;
        
        for(int i =1;i<nums.size();i++){
            int maxVal = INT_MIN;
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]){ // if increasing
                    maxVal = max(maxVal, lisarr[j]+1);// find max  of lisarr + self 
                }
            }
            lisarr[i] = max(1, maxVal);
        }
        
        // for ans, take max of all lisarr
        int ans = INT_MIN;
        for(int k=0;k<nums.size();k++){
            ans = max(ans, lisarr[k]);
        }
        
        return ans;
        */
        



        // O(n*log n)
        
        // [1,7,8,4,5,6,-1,9]
        // maintain list "seq"
        // if (i+1)>i -> add to seq
        // else find mid of seq(lower bound) and replace with i+1 value
        // wont give the LIS itself but just correct length of it. 
        
        vector<int> seq;
        int max = nums[0];
        seq.push_back(max);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max) {
                seq.push_back(nums[i]);
                // max =nums[i];
            }
            else {
                 auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
                *it = nums[i];   
                // max = seq[seq.size()-1];
                // cout<<*lower_bound(seq.begin(), seq.end(), nums[i])<<endl;
            }
            max = seq[seq.size()-1];
        }
        return seq.size();
        
    }
};



int main(){


    return 0;
};