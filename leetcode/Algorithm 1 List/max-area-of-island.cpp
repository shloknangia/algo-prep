#include <iostream>
#include<bits/stdc++.h>
using namespace std;

    // 695. Max Area of Island
    // Medium

    // You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    // The area of an island is the number of cells with a value 1 in the island.

    // Return the maximum area of an island in grid. If there is no island, return 0.

    

    // Example 1:

    // Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    // Output: 6
    // Explanation: The answer is not 11, because the island must be connected 4-directionally.

    // Example 2:

    // Input: grid = [[0,0,0,0,0,0,0,0]]
    // Output: 0

    

    // Constraints:

    //     m == grid.length
    //     n == grid[i].length
    //     1 <= m, n <= 50
    //     grid[i][j] is either 0 or 1.



class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int areaij = calculateAreaForij(grid, i, j, n, m);
                    maxArea = max(maxArea, areaij);
                }
            }   
        }
            
        return maxArea;
    }
    
    
    int calculateAreaForij(vector<vector<int>>& grid, int i, int j, int n ,int m){
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=n || j>=m ||grid[i][j] == 0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int area = 0;
        area += calculateAreaForij(grid, i+1, j, n, m);
        area += calculateAreaForij(grid, i-1, j, n, m);
        area += calculateAreaForij(grid, i, j+1, n, m);
        area += calculateAreaForij(grid, i, j-1, n, m);
            
        return 1+area;
    }
    
    
};



int main(){


    return 0;
};