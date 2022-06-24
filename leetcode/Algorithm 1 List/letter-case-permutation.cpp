#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 784. Letter Case Permutation
// Medium

// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]

 

// Constraints:

//     1 <= s.length <= 12
//     s consists of lowercase English letters, uppercase English letters, and digits.


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        
        set<string> res_s;
        vector<string> res;
        // res_s.insert(s);
        findpermutation(s,0, res_s);
        
        for(auto a: res_s){
            
            res.push_back(a);
        }
        return res;
        
    }
    
    void findpermutation(string s, int j , set<string>& res){
        if(j == s.length()){
            // cout<<s<<endl;
            res.insert(s);
            return;
        } 
        

        char newVal=s[j];
        if(s[j]>=97 &&s[j]<123){
            newVal = s[j] - 32;
        }
        if(s[j]>=65 &&s[j]<91){
            newVal = s[j] + 32;
        }
        findpermutation(s, j+1, res);
            
        swap(s[j], newVal);
        findpermutation(s, j+1, res);
        // swap(s[j], newVal);

    }
        
};


int main(){


    return 0;
};