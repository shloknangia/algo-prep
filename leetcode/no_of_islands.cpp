#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int noOfIslands= 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    noOfIslands += visitThisPosition(grid, i, j, n, m);
                }
            }
        }
        
        return noOfIslands;
    }
    
    
    int visitThisPosition(vector<vector<char>>& grid, int i, int j, int n, int m){
        
        // need to visit i,j
        
        if(i<0 || i==n || j<0 || j==m  || grid[i][j] == '0'){
            return 0;
        }
        
        grid[i][j] = '0'; //visited
        
        // need to visit adjacent land
        
        visitThisPosition(grid, i, j+1, n, m);
        // cout<<"i,j+1"<<endl;
        visitThisPosition(grid, i, j-1, n, m);
        // cout<<"i, j-1"<<endl;
        
        visitThisPosition(grid, i+1, j, n, m);
        // cout<<"i+1, j"<<endl;
        
        visitThisPosition(grid, i-1, j, n, m);
        // cout<<"i-1, j"<<endl;
        
        return 1;
        
    }
};




int main(){


    return 0;
};