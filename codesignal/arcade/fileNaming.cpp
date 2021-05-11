// You are given an array of desired filenames in the order of their creation. Since two files cannot have equal names, the one which comes later will have an addition to its name in a form of (k), where k is the smallest positive integer such that the obtained name is not used yet.

// Return an array of names that will be given to the files.

// Example

// For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
// fileNaming(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].


#include<bits/stdc++.h>
using namespace std;

vector<string> fileNaming(vector<string> names) {
    
    vector<string> out;
    for(string n: names){
        string name = n;
        
        int count = 0;
        string newname = n;
        while(find(out.begin(), out.end(), name) != out.end()){
            string postfix  ="";
            if(count ==0){
                count++;
                postfix = "(1)";
            }
            else{
                int num = 0;
                bool f = false;
                for(char c:name){
                    if(c == ')'){
                        f = false;
                    }
                    if(f){
                        cout<<num<<"\t"<<c<<"\t"<<c-'0'<<endl;
                        num = num*10 + (c-'0');
                    }
                    if(c == '('){
                        num = 0;
                        f = true;
                    }
                    
                }
                postfix = (num==0)?"(1)":"(" + to_string(num+1)+")";
            }
            name = n + postfix;
        }
        
        
        cout<<endl;
        out.push_back(name);
    }
    return out;
}

std::vector<std::string> fileNaming(std::vector<std::string> names) {
    set<string> mp;
    vector<string> ans;
    for(string s:names){
        int t = 0;
        string ss = s;
        while(mp.find(ss)!=mp.end())
            ss = s +"("+to_string(++t)+")";
        mp.insert(ss);
        ans.push_back(ss);
    }
    return ans;
}
