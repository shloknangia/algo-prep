#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


class Solution {
    
    
public:
    
    // vector<int> canReach (1000,-1);
    bool canJump(vector<int>& nums) {
        vector<int> canReach (nums.size(),-1);
        if(nums.size() <1){
            return true;
        }
        
        int i = 0;
        int n = nums.size();
        return tryJumping(nums, i, n, canReach);
        
    }
    
    
    bool tryJumping(vector<int>& nums, int i, int n, vector<int>& canReach){
        
        if(i == n-1){
            canReach[i] = 1;
            return true;
            //reached last
        }
        
        if(nums[i] == 0  || i>=n) return false;
        
        for(int k = 1;k<=nums[i];k++){
            
            if(canReach[i+k] != -1){
                if(canReach[i+k] ==1) return true;
            }
            else{
                if(tryJumping(nums, i+k, n, canReach)){
                    canReach[i+k] = 1;
                    return true;
                }
                else{
                    canReach[i+k] = 0;
                }
            }
                
            
        }
        
        return false;
    }
    
    
    
//     bool tryJumping(vector<int>& nums, int i, int n){
        
        
        
//         if(i == n-1){
//             return true;
//             //reached last
//         }
        
//         if(nums[i] == 0  || i>=n) return false;
        
//         for(int k = 1;k<=nums[i];k++){
//             if(tryJumping(nums, i+k, n)){
//                 return true;
//             }
            
//         }
        
//         return false;
//     }
    
    
};




int main(){


    return 0;
};