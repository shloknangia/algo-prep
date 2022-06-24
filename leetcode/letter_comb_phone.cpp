#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = ""
// Output: []

// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

 

// Constraints:

//     0 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].




class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<char> > m;
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r', 's'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y', 'z'};
        
        
        vector<string> result;
        if(digits.size() == 0 ) return result;
        char temp[5] = {' '};
        findLetterComb(m , digits, 0, result,temp);
        return result;
        
    }
    
    
    void findLetterComb(unordered_map<char, vector<char> > m, string digits, int i, vector<string> &result, char *temp){
        
        cout<<"i"<<i<<endl;
        
        if(digits[i] == '\0' || i== digits.size()){
            result.push_back(temp);
            temp[i] = '\0';
            return;
        }
        
        for(int j=0;j<m[digits[i]].size();j++){
        
            cout<<"i: "<<i<<" j: "<<j<<" dig:"<<digits[i]<<" value: "<<m[digits[i]][j]<<" temp: "<<temp<<endl;
            temp[i] =m[digits[i]][j];
            cout<<temp<<endl;
            findLetterComb(m , digits, i+1, result, temp);
        }
        
        
        
    }
};



int main(){


    return 0;
};