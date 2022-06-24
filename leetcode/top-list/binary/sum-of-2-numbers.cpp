#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 371. Sum of Two Integers
// Medium

// Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

// Example 1:

// Input: a = 1, b = 2
// Output: 3

// Example 2:

// Input: a = 2, b = 3
// Output: 5

 

// Constraints:

//     -1000 <= a, b <= 1000



class Solution {
public:
    int getSum(int a, int b) {
                
        // 5 - (0101)    
        // 2 - (0010)
        // 3 - (0011)
        // ^ - (0001) // calculate the sum(without carry)
        // & - (0010) ->  <<1 = (0100) // calculate the carry then shift by 1 for next letter
        //  now add again untill carry is 0
    
        int sum = a;
        while(b){
            sum = a^b;
            b = (unsigned)(a&b)<<1;
            a = sum;
        }

        return sum;
        
    }
};



int main(){


    return 0;
};