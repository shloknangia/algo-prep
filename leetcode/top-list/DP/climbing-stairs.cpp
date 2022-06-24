#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// 70. Climbing Stairs
// Easy

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

 

// Constraints:

//     1 <= n <= 45


class Solution {
    
public:
    int climbStairs(int n) {
        // if(n<0) return 0;
        // if(n ==0) return 1;
        // return climbStairs(n-1)+ climbStairs(n-2);
        
        vector<int> v(n+1, 0);
        v[0]  =1;
        for(int i=1;i<=n;i++){
            
            int n1 = (i-1)>=0?v[i-1]:0;
            int n2 = (i-2)>=0?v[i-2]:0;
            v[i] = n1+n2;
            // cout<<i<<" "<<n1<<" "<<n2<<" "<<v[i]<<endl;
        }
        return v[n];
        
    }
};

int main(){


    return 0;
};