#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 139. Word Break
// Medium

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

 

// Constraints:

//     1 <= s.length <= 300
//     1 <= wordDict.length <= 1000
//     1 <= wordDict[i].length <= 20
//     s and wordDict[i] consist of only lowercase English letters.
//     All the strings of wordDict are unique.


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> m;
        
        for(auto w: wordDict){
            m[w] = true;
        }
        
//         int i =0, j =0;
//         while(j<s.length()){
//             if(m[s.substr(i, j-i+1)]){
//                 i = j+1;
//             }
//             j++;
//         }
        
//         if(i == s.length() && j == s.length()) return true;
//         else return false;
        
        /// ^ fails at "aaaaaaa" & ["aaaa", "aaa"]
        
        
        vector<bool> dp (s.length()+1, false);
        
        dp[0] = true;
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                
                if(dp[j] && m[s.substr(j, i-j)]){
                    dp[i]=true;
                    break;
                }
                // cout<<s[i]<<" "<<s[j]<<" "<<dp[i]<<endl;
            }
        }
        
        return dp[s.size()];
        
    }
};


int main(){


    return 0;
};