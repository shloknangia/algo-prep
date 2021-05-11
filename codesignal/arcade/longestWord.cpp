// Define a word as a sequence of consecutive English letters. Find the longest word from the given string.

// Example

// For text = "Ready, steady, go!", the output should be
// longestWord(text) = "steady".


#include<bits/stdc++.h>
using namespace std;

string longestWord(string text) {
    int count = 0;
    int start = -1;
    map<int, pair<int,int>> m;
    for(int i=0;i<text.length();i++){
        if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')){
            cout<<text[i]<<endl;
            if(start == -1){
                start = i;
            }
            count++;
        }
        else{
            if(count!=0){    
                m.insert(make_pair(count,make_pair(start, i)));
                start = -1;
                count = 0;
            }
        }
    }
    
    if(count!=0){    
        m.insert(make_pair(count,make_pair(start, 99)));
        start = -1;
        count = 0;
    }
    auto maxEntry = *max_element(m.begin(), m.end());
    return text.substr(maxEntry.second.first, maxEntry.first);
}
