#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 567. Permutation in String
// Medium

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

 

// Constraints:

//     1 <= s1.length, s2.length <= 104
//     s1 and s2 consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        int win = s1.length();
        int n= s2.length();
        
        sort(s1.begin(),s1.begin());
        
        // if(n<win) return false;
        for(int i=0;i<=n-win;i++){
            cout<<i<< " "<<i+win<<" "<<s1<<" "<<s2.substr(i, win)<<endl;
            if(s1 == sortthis(s2.substr(i, win))){
                return true;
            }
        }
        
        return false;
        
    }
               
               
   string sortthis(string s){
       cout<<s<<endl;
       sort(s.begin(), s.end());
       return s;
   }

};


int main(){


    return 0;
};