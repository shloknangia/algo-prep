#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 557. Reverse Words in a String III
// Easy

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"

 

// Constraints:

//     1 <= s.length <= 5 * 104
//     s contains printable ASCII characters.
//     s does not contain any leading or trailing spaces.
//     There is at least one word in s.
//     All the words in s are separated by a single space.



class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int start = 0;
        string res = "";
        while(i<=n){
            
            if(s[i] == ' ' ){
                addWordToString(res, s, start, i);
                res += ' ';
                start = i+ 1;
            }
            
            if(i == n){
                addWordToString(res, s, start, i);
            }
            
            i++;
        }
        return res;
        
    }
    
    void addWordToString(string &res, string s , int start, int end){
        for(int i = end-1;i>=start;i--){
            res += s[i];
        }
    }
};



int main(){


    return 0;
};