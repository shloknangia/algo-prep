#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// 994. Rotting Oranges
// Medium

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 10
//     grid[i][j] is 0, 1, or 2.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count =0;
        int prevones = -1;
        while(!isAllRotten(grid)){
            int onesleft = visitAdjacentNodes(grid);
            // cout<<onesleft<<endl;
            if(onesleft == prevones) return -1;
            else prevones = onesleft;
            count++;
        }
        
        return count;
        
    }
    
    
    int visitAdjacentNodes(vector<vector<int>>& grid){
        vector<vector<int>> copy = grid;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(copy[i][j] == 2){
                    if(i<n-1 && grid[i+1][j]==1) grid[i+1][j] = 2;
                    if(i>0 && grid[i-1][j]==1) grid[i-1][j] = 2;
                    if(j<m-1 && grid[i][j+1]==1) grid[i][j+1] = 2;
                    if(j>0 && grid[i][j-1]) grid[i][j-1] = 2;
                }
            }
        }
        int count;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
        
    }
    
    int isAllRotten(vector<vector<int>> grid){
        bool ans = true;
        // int count = 0
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    // count++;
                    ans =  false;
                }
            }
        }
        return ans;
        
    }
};





int main(){


    return 0;
};