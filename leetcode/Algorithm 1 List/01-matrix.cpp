#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 542. 01 Matrix
// Medium

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

 

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 104
//     1 <= m * n <= 104
//     mat[i][j] is either 0 or 1.
//     There is at least one 0 in mat.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<vector<int>> res;//(m, new vector<int>(n,0));
//         vector<vector<int>> vis;
//         for(int i=0;i<m;i++){
//             vector<int> temp(n, 0);
//             vis.push_back(temp);
//         }
        
//         for(int i=0;i<m;i++){
//             vector<int> temp;
//             for(int j=0;j<n;j++){
//                 if(mat[i][j] == 0){
//                     temp.push_back(0);    
//                 }
//                 else{
//                     temp.push_back(getdistToZero(mat, i, j, m, n, vis,0));
//                     // resetvis(vis);    
//                 }
                
//             }
//             res.push_back(temp);
//         }
//         return res;
        
        
//         DP
        
        vector<vector<int>> dp(mat.size(),vector<int> (mat[0].size(),0));
        int m = mat.size();
        int n = mat[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }else{
                    int u = i>0?dp[i-1][j]:m*n;
                    int l = j>0? dp[i][j-1]: m*n;
                    dp[i][j] = min(l, u)+1;
                }
            }
        }
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }else{
                    int d = i<m-1?dp[i+1][j]:m*n;
                    int r = j<n-1? dp[i][j+1]: m*n;
                    dp[i][j] = min(min(d,r)+1,dp[i][j]);
                }
            }
        }
        return dp;
    }
    
    
    void resetvis(vector<vector<int>>& vis){
        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[0].size();j++){
                vis[i][j] = 0;
            }
        }
    }
    
    
    int getdistToZero(vector<vector<int>> mat, int i, int j, int m, int n, vector<vector<int>>& vis, int d){
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] == 1) return INT_MAX-1;
        
        if(mat[i][j] == 0) return d;
        vis[i][j] = 1;
        int l = getdistToZero(mat, i, j-1,m,n,vis ,d+1);
        int r = getdistToZero(mat, i, j+1,m,n,vis ,d+1);
        int u = getdistToZero(mat, i-1, j,m,n,vis ,d+1);
        int dn = getdistToZero(mat, i+1, j,m,n,vis ,d+1);
        vis[i][j] = 0;
        vector<int> ans = {l, r, u, dn};
        return *min_element(ans.begin(), ans.end());
        
        // int ans = 0;
        // // if(l>0 || r>0 || u>0 || d>0){
        //     ans = min(l, min(r,min(u,dn)));
        // // }
        // return ans;
        
    }
};


int main(){


    return 0;
};