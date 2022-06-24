#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 344. Reverse String
// Easy

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

 

// Constraints:

//     1 <= s.length <= 105
//     s[i] is a printable ascii character.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i= 0;
        int n= s.size();
        int j = n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        // reverse(s.begin(), s.end());
        
    }
};

int main(){


    return 0;
};