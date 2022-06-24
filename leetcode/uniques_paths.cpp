#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

 

// Example 1:

// Input: m = 3, n = 7
// Output: 28

// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Example 3:

// Input: m = 7, n = 3
// Output: 28

// Example 4:

// Input: m = 3, n = 3
// Output: 6



class Solution {
public:
    int uniquePaths(int m, int n) {
        int uniPaths=0;
        vector<vector<int>> pathArr (m, vector<int>(n, -1));
        // getUniPathsFromij(0,0,m,n,uniPaths,pathArr); // recursive soln
        
        
        pathArr[m-1][n-1] = 0;
        for(int i=m-1;i>=0;i--){
            pathArr[i][n-1] = 1;//m-1 -i; //min no of steps
        }
        
        for(int j=n-1;j>=0;j--){
            pathArr[m-1][j] = 1;//n-1 -j;//min no of steps
        }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                
                if(pathArr[i][j] == -1){
                    pathArr[i][j] = pathArr[i+1][j] + pathArr[i][j+1] ;
                        // 1 + min(pathArr[i+1][j], pathArr[i][j+1]); //min no of steps
                }
                
            }
        }
        // print 
    //         for(int i=0;i<m;i++){
    //             for(int j=0;j<n;j++){
    //                 cout<<pathArr[i][j]<<" ";
    //             }
    //             cout<<endl;
    //         }
        
        
        
        // return uniPaths; // recursive soln
        return pathArr[0][0];
        
    }
    
    
    
    
    // recursive soln
    //     void getUniPathsFromij(int i, int j, int m , int n, int &uniPaths){
    //         if((i == m-1) && (j == n-1)){
    //             uniPaths++;
    //             return;
    //         }
            
    //         if(i>=m || j>=n) return;
            
    //         getUniPathsFromij(i+1,j, m, n,uniPaths);    
            
    //         getUniPathsFromij(i,j+1, m, n,uniPaths);
            
            
    //     }
};



int main(){


    return 0;
};