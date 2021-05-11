// Write a function that reverses characters in (possibly nested) parentheses in the input string.

// Input strings will always be well-formed with matching ()s.

// Example

//     For inputString = "(bar)", the output should be
//     reverseInParentheses(inputString) = "rab";
//     For inputString = "foo(bar)baz", the output should be
//     reverseInParentheses(inputString) = "foorabbaz";
//     For inputString = "foo(bar)baz(blim)", the output should be
//     reverseInParentheses(inputString) = "foorabbazmilb";
//     For inputString = "foo(bar(baz))blim", the output should be
//     reverseInParentheses(inputString) = "foobazrabblim".
//     Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim"

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseInParentheses(string inputString) {
    stack<char> s;
    string output = "";
    for(int i = 0;i<inputString.length();i++){
        if(inputString[i]=='('){
            s.push(i);
        }
        else if(inputString[i]==')'){
            // cout<<*(inputString.begin()+s.top())<<'\t'<<*(inputString.begin()+i)<<endl;
            reverse(inputString.begin()+s.top(),inputString.begin()+i );
            s.pop();
        }
    }
    
    for(int i = 0;i<inputString.length();i++){
        if(inputString[i]!='(' && inputString[i]!=')'){
            output.push_back(inputString[i]);
        }
    }
    return output;
}

