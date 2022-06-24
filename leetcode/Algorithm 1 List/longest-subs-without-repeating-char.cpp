#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters
// Medium

// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

// Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of English letters, digits, symbols and spaces.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        
        int n = s.length();
        if(n==0) return 0;
        
        unordered_map<int, int> m;
        int length = 0, cmax = 0;
        int i = 0, j=0;
        while(j<n){
            if(m[s[j]] == 0){
                // acquire till copy is met/ becomes invalid
                m[s[j]]++;
                cmax++;
            }else{
                
                // release values till all are single/ valid or all unique
                while(s[j] != s[i]){
                    m[s[i++]]--;
                    cmax--;
                }
                
                i++;    
            }
            j++;
            length = max(cmax, length);
        }
        
        
        return length;   
    }
    
};


int main(){


    return 0;
};