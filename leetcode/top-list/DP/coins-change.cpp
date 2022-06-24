#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 322. Coin Change
// Medium

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

 

// Constraints:

//     1 <= coins.length <= 12
//     1 <= coins[i] <= 231 - 1
//     0 <= amount <= 104



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> mincoins(amount+1, INT_MAX);
        if(amount == 0) return 0;
        mincoins[0] = 0;
        for(int i =0;i<coins.size();i++){
            if(amount>=coins[i])
                mincoins[coins[i]] = 1;
        }
        
        for(int i =1;i<=amount;i++){
            for(int j =0;j<coins.size();j++){
                if(i-coins[j]>0 && mincoins[i - coins[j]]!=INT_MAX){
                    mincoins[i] = min(mincoins[i], 1+ mincoins[i - coins[j]]);
                    // cout<<mincoins[i]<<endl;
                }
                    
            }
            
        }
        // 0 1 2 3
        // 0  M 1
        
        return (mincoins[amount] == INT_MAX)? -1: mincoins[amount];
        
//         if(amount <= 0) return -1;
//         for(int i=0;i<coins.size();i++) if(coins[i] == amount) return 1;
        
//         int minCoins = INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             int isNewAmountPossible = coinChange(coins, amount-coins[i]);
//             minCoins = min(minCoins,1+  (isNewAmountPossible!=-1 ? isNewAmountPossible : 0));
//         }
//         return minCoins;
        
    }
};



int main(){


    return 0;
};