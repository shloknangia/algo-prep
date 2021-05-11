// Given an array of equal-length strings, you'd like to know if it's possible to rearrange the order of the elements in such a way that each consecutive pair of strings differ by exactly one character. Return true if it's possible, and false if not.

// Note: You're only rearranging the order of the strings, not the order of the letters within the strings!

// Example

//     For inputArray = ["aba", "bbb", "bab"], the output should be
//     stringsRearrangement(inputArray) = false.

//     There are 6 possible arrangements for these strings:
//         ["aba", "bbb", "bab"]
//         ["aba", "bab", "bbb"]
//         ["bbb", "aba", "bab"]
//         ["bbb", "bab", "aba"]
//         ["bab", "bbb", "aba"]
//         ["bab", "aba", "bbb"]

//     None of these satisfy the condition of consecutive strings differing by 1 character, so the answer is false.

//     For inputArray = ["ab", "bb", "aa"], the output should be
//     stringsRearrangement(inputArray) = true.

//     It's possible to arrange these strings in a way that each consecutive pair of strings differ by 1 character (eg: "aa", "ab", "bb" or "bb", "ab", "aa"), so return true.

#include<bits/stdc++.h>
using namespace std;

int diff(string a, string b){
    int count =0;
    for(int i=0;i<a.length();i++){
        if((a[i]-'0') != (b[i]-'0')){
            count++;
        }
    }
    // cout<<a<<"|"<<b<<"|"<<count<<endl;
    return count;
}

bool stringsRearrangement(vector<string> inputArray) {
    sort(inputArray.begin(), inputArray.end());
    // for(string s :inputArray) cout<<s<<endl;
    int itr = 0;
    do{
        // cout<<itr++<<endl;
        // for(string s :inputArray) cout<<s<<endl;
        bool flag = true;
        for(int i=0;i+1<inputArray.size();i++){
            if(diff(inputArray[i], inputArray[i+1])!= 1){
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }while(next_permutation(inputArray.begin(), inputArray.end()));
    // for(string s :inputArray) cout<<s<<endl;
    return false;
}
