#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 152. Maximum Product Subarray
// Medium

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -10 <= nums[i] <= 10
//     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.




class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProd = INT_MIN;
        int cprod = 1;
        int n = nums.size();
        
        // ans can be from starting (0 -> mid) of arr or (mid-> end)or arr [ without zero]
        //a*(ans)*b == not possible
        // check all cases where a, b, ans can be -ve ot +ve
        // now with zero -> and will be from starting index next to 0 -> mid ot mid -> end
        
        //calculate max prod from start

        for(int i=0;i<n;i++){
            cprod *= nums[i];
            // cprod = max(cprod, nums[i]);
            
            maxProd = max(maxProd, cprod);
            
            if(cprod == 0) cprod = 1;
        }
        cprod = 1;

        //calculate max prod from end
        for(int i=n-1;i>=0;i--){
            cprod *= nums[i];
            // cprod = max(cprod, nums[i]);
            
            maxProd = max(maxProd, cprod);
            
            if(cprod == 0) cprod = 1;
        }

        // return max of both;
        return maxProd;
    }
};

int main(){


    return 0;
};