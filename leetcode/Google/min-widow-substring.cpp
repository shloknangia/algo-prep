#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 76. Minimum Window Substring
// Hard

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

 

// Constraints:

//     m == s.length
//     n == t.length
//     1 <= m, n <= 105
//     s and t consist of uppercase and lowercase English letters.

 
// Follow up: Could you find an algorithm that runs in O(m + n) time?




class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> map(128, 0);
        for(auto a: t){
            map[a]++;
        }
        
        int win = INT_MAX;
        int i=0, j=0, head = 0;
        int counter = t.length();
        
        while(j<s.length()){
            if(map[s[j++]]-- >0 ) counter--;
            
            while(counter == 0){
                if(j-i<win) win = j-(head=i);
                if(map[s[i++]]++ == 0) counter++;
            }
            
        }
        
        if(win == INT_MAX){
            return "";
        }
        else{
            return s.substr(head, win);
        }   
    }
};

int main(){


    return 0;
};

