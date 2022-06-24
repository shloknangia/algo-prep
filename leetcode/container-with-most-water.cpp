#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 11. Container With Most Water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:

// Input: height = [1,1]
// Output: 1

 

// Constraints:

//     n == height.length
//     2 <= n <= 105
//     0 <= height[i] <= 104

class Solution {
public:
    int maxArea(vector<int>& height) {
                
        // find first max index
        int n = height.size();
        int m = height[0], index = 0;        
        
        int maxv = INT_MIN;
        // O(N^2)
        // for(int i=0;i<n;i++){
        //     for(int j=n-1;j>index; j--){
        //         maxv = max((j-i)*min(height[i], height[j]), maxv);
        //     }
        // }
        
        
        int i = 0, j = n-1;
        while(i<j){
            int h = min(height[i], height[j]);
            maxv = max((j-i)*h, maxv);
            while(height[i]<= h && i<j) i++;
            while(height[j]<=h && i<j) j--;
        }
        
            
        return maxv;
        
        
    }
};


int main(){


    return 0;
};