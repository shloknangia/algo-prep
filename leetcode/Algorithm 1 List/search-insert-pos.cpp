#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 35. Search Insert Position
// Easy

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

 

// Constraints:

//     1 <= nums.length <= 104
//     -104 <= nums[i] <= 104
//     nums contains distinct values sorted in ascending order.
//     -104 <= target <= 104

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int s =0;
        int e = nums.size()-1;
        int index = -1;
        if(target<=nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]>=target && nums[mid-1]<target){
                index = mid;
                break;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            
            else{
                e =mid-1;
            }
                
            
        }
        
        return index!=-1?index:nums.size();
        
    }
};



int main(){


    return 0;
};