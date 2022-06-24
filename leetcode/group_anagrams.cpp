#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {        
        unordered_map<string, vector<string>> m;
        for(string s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        
        vector<vector<string>> anagrams;
        for(auto i:m){
            anagrams.push_back(i.second);
        }
        return anagrams;
    }
};

int main(){


    return 0;
};