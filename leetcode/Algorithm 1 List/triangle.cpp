#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 120. Triangle
// Medium

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:

// Input: triangle = [[-10]]
// Output: -10

 

// Constraints:

//     1 <= triangle.length <= 200
//     triangle[0].length == 1
//     triangle[i].length == triangle[i - 1].length + 1
//     -104 <= triangle[i][j] <= 104

 
// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle, int r = 0, int c = 0, int sum = 0) {
        /*
        if(r == triangle.size() || c == triangle[r].size()) return sum;
        int s = 10002;
        for(int i = c;i<triangle[r].size() && i<c+2;i++){
            s = min(s, minimumTotal(triangle, r+1, i, sum+triangle[r][i]));
            
        }
        return s;
        */
        
        
        //    2(2)
        //   3(5) 4(6)
        //  6(11) 5(10) 7(13)
        // 4(15) 1(11) 8(18) 3(16)
              
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle[triangle.size()-1].size(), 100002));
        
        dp[0][0] = triangle[0][0];
        
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                int v1 = 100002;
                if(j-1>=0) v1 = dp[i-1][j-1];
                int v2 = 100002;
                v2 = dp[i-1][j];
                dp[i][j] = triangle[i][j] + min(v1, v2);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        int minv = INT_MAX;
        for(int i=0;i<dp[0].size();i++){
            minv = min(minv, dp[dp.size()-1][i]);
        }
        return minv;
        
        
    }
};


int main(){


    return 0;
};