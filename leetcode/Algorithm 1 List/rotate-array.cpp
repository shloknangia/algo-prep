#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 189. Rotate Array
// Medium

// Given an array, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

 

// Constraints:

//     1 <= nums.length <= 105
//     -231 <= nums[i] <= 231 - 1
//     0 <= k <= 105

 

// Follow up:

//     Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
//     Could you do it in-place with O(1) extra space?



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // if(!k) return nums;
        
        // O(KN)
//         while(k--){
            
//             int temp = nums[nums.size()-1];
//             for(int i=0;i<nums.size();i++){
//                 swap(temp, nums[i]);
//             }
            
//         }
        
        // return nums;
        
        // [1,2,3,4,5,6,7,1,2,3,4,5,6,7]
        
        int n =nums.size();
        // while(k--){
        //     int temp = nums[n-1];
        //     print(nums);
        //     cout<<temp;
        //     nums.erase(nums.begin()+n-1);
        //     nums.emplace(nums.begin(), temp);
        // }
        
        // O(n) but O(n) space
//         vector<int> res;
//         if(n!=1){
//             for(int i=n-(k%n);i<n;i++){
//                 res.push_back(nums[i]);
//             }
//             for(int i=0;i<n-(k%n);i++){
//                 res.push_back(nums[i]);
//             }

//             nums = res;    
//         }
        
        // 1,2,3,4,5,6,7
        // 7,6,5,,4,3,2,1,
        // 5,6,7,1,2,3,4,
        
        // O(N) time and O(N) space
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        
        // [1,2,3,4,5,6,7]
        // [5,6,7,4,1,2,3]
    }
    
    void print(vector<int> v){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};



int main(){


    return 0;
};