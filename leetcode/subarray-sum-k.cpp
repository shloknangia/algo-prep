#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 560. Subarray Sum Equals K
// Medium

// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -1000 <= nums[i] <= 1000
//     -107 <= k <= 107



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int win = 0;
        int count=0;
        

        //O(N^3)
        // while(win<n){
        //     for(int i=0;i<n-win;i++){
        //         if(sumOf(nums, i, i+win) == k) count++;
        //     }
        //     win++;
        // }
        
        
        //O(N^2)
//         vector<int> csum(n,0);
//         csum[0] = nums[0];
//         for(int i=1;i<n;i++){
//             csum[i] = nums[i] + csum[i-1];
//         }
        
        
//         for(int i=n-1;i>=0;i--){
//             if(csum[i] == k) count++;
//             for(int j=i-1;j>=0;j--){
//                 if(csum[i] - csum[j] == k)  count++;
//             }
//         }
        
        
//         int sum = INT_MIN;
//         int csum = 0;
//         for(int i=0;i<n;i++){
//             csum+= nums[i];
//             csum = max(csum, 0);
            
//             // sum = max(sum, csum);
//             if(csum == k){
//                 csum = nums[i];
//                 count++;
                
//             } 
            
//         }
        
        
        
        //O(N)
     // [ 1, 7, 6, 2, 3, 3, 2 ]
     //   |  |  |  |  |  |  |
     //   ====  |  |  |  |  |
     //    y-k  ====  |  |  |
     //           k
     //            |  |  |  |
     //   ===========
     //        y 
                  
        
        
        unordered_map<int, int> freqSum;
        freqSum[0] = 1; // sum 0 is seen
        int csum = 0; 
        for(int i=0;i<n;i++){
            // track cumulative sum/ sum till now
            csum += nums[i];
            
            // check , if (csum -k) is ever seen before
            if(freqSum[csum-k]){
                // if yes, add how many times
                count += freqSum[csum-k];
            }
            
            // mark current sum as seen and increase sum
            freqSum[csum]++;
        }
        
        return count;
    }
    
    int sumOf(vector<int> nums, int i, int j){
        int s = 0;
        for(int k=i;k<=j;k++) s+=nums[k];
        return s;
    }
};




int main(){


    return 0;
};