#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string Minimum_Window(string s, string t){ // string and pattern
    unordered_map<char, int> m;

    int count = 0;
    int ans = INT_MAX;
    int start = 0;

    for(auto c: t){
        if(m.find(c) == m.end() || m[c] == 0){
            count++; // need to take care of
        }
        m[c]++; // adding each char from pattern
    }

    int i=0, j=0;
    while(j<s.length()){
        m[s[j]]--;

        if(m.find(s[j]) == m.end() || m[s[j]] == 0){
            count--; // if count 0, no need to worry about it
        }

        if(count == 0){ // all are encountered
            while(count ==0){ // try for min window
                if(ans > j-i+1){
                    ans = min(ans, j-i+1);
                    start = i;
                }
                m[s[i]]++; // pushing i back to map
                if(m[s[i]]>0){
                    count++;
                }
                i++;
            }
        }

        j++;
    }
    
    if(ans != INT_MAX){
        return s.substr(start, ans);
    }
    else{
        return "-1";
    }
}

int main(){

    string s = "ADOBECODEBANC";
    string t = "ABC";
     
    cout<<"Smallest window that contain all character : "<<endl;
    cout << Minimum_Window(s, t);

    /*
    OUTPUT: 
    Smallest window that contain all character :
    BANC
    */

    return 0;
};