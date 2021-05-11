// Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.

// Example

//     For s = "abacabad", the output should be
//     firstNotRepeatingCharacter(s) = 'c'.

//     There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

//     For s = "abacabaabacaba", the output should be
//     firstNotRepeatingCharacter(s) = '_'.

//     There are no characters in this string that do not repeat.

#include<bits/stdc++.h>
using namespace std;

char firstNotRepeatingCharacter(string s) {
    map<char, int> occ;
    for(int i=0;i<s.length();i++){
        auto it = occ.find(s[i]);
        if(it==occ.end()){
            occ.insert((make_pair(s[i], 1)));
        }
        else{
            occ[s[i]] +=1;
        }
    }
    
    for(int i=0;i<s.length();i++){
        auto it = occ.find(s[i]);
        if(it!=occ.end() && occ[s[i]] ==1){
            return it->first;
        }
    }
    return '_';
}
