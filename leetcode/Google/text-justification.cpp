#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// 68. Text Justification
// Hard

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified and no extra space is inserted between words.

// Note:

//     A word is defined as a character sequence consisting of non-space characters only.
//     Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//     The input array words contains at least one word.

 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified becase it contains only one word.

// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

 

// Constraints:

//     1 <= words.length <= 300
//     1 <= words[i].length <= 20
//     words[i] consists of only English letters and symbols.
//     1 <= maxWidth <= 100
//     words[i].length <= maxWidth





class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        // divide words
        int num_words = words.size();
        
        vector<string> res;
        vector<int> res_sizes;
        int cursize = 1;
        int j = 0;
        string curstr = words[0];
        for(int i=1;i<num_words;i++){
            if(curstr.length() + 1 + words[i].length() <= maxWidth){
                curstr = curstr+" "+ words[i];
                cursize++;
            }
            else{
                res.push_back(curstr);
                curstr = words[i];
                res_sizes.push_back(cursize);
                cursize = 1;
                j++;
            }
        }
        res.push_back(curstr);
        
        
        // adding spaces
        for(int i =0;i<res.size();i++){
            // cout<<w<<endl;
            // calc spaces to be added
            int space_to_add = maxWidth - res[i].length();
            
            
            if((i == res.size()-1) || res_sizes[i] == 1){
                    string justifiedstr =res[i] ;
                    while(space_to_add--){
                        justifiedstr += ' ';
                    }
                    res[i] = justifiedstr; 
                }
            else{
                
                // calculate spaces for each pos
                vector<int> spaces( res_sizes[i]-1,0);
                int len = space_to_add;
                while(len>0){
                    for(int p=0;p<res_sizes[i]-1;p++){
                        if(len>0){
                            spaces[p]++;
                            len--;
                        }
                            
                    }
                }
                for(auto s: spaces){
                    cout<<s<<" ";
                }
                cout<<endl<<endl;
                
                
                
                while(space_to_add != 0){
                    cout<<res[i]<< " "<<res[i].length()<<" "<<space_to_add<<endl;
                    // for last
                    // int space_for_each = space_to_add/(re_sizes[i]-1);
                    string justifiedstr = "";
                    int space_index = 0;
                    for(auto ch: res[i]){
                        if(ch != ' '){
                            justifiedstr += ch;
                        }
                        else{
                            justifiedstr += ch;
                            for(int k =0;k<spaces[space_index];k++){
                                justifiedstr += ' ';
                                space_to_add--;
                            }
                            space_index++;
                        }

                    }       
                    res[i] = justifiedstr;
                    
                     
                } 
                
            }
                        
        }
       
        return res;
        
    }
    
    
    
//     l1, l2, l3,.. ----- w
//     // divide words
//         cstr + l <w untill false
//         set of words
        
//     // add padding
//         if not last line
//         nw = 3, len = 10 ->> add 16-10 = 6 / nw-1
    
    // 4, 4,3  11/3 = 3
};

int main(){


    return 0;
};