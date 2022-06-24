#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// 231. Power of Two
// Easy

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16

// Example 3:

// Input: n = 3
// Output: false

 

// Constraints:

//     -231 <= n <= 231 - 1

 
// Follow up: Could you solve it without loops/recursion?



class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
        if(n==1) return true;
        if(n%2 == 0){
            return isPowerOfTwo(n/2);
        }
        else{
            return false;
        }*/

        
        /*int count=0;
        if(n<0) return false;
        while(n){
            if(n&1) count++;
            n >>=1;
        }
        return count==1;*/
        
        
    //         There's a nice bit-trick that can be used to check if a number is power of 2 efficiently. As already seen above, n will only have 1 set bit if it is power of 2. Then, we can AND (&) n and n-1 and if the result is 0, it is power of 2. This works because if n is power of 2 with ith bit set, then in n-1, i will become unset and all bits to right of i will become set. Thus the result of AND will be 0.

    // If n is a power of 2:
    // n    = 8 (1000)
    // n-1  = 7 (0111)
    // ----------------
    // &    = 0 (0000)         (no set bit will be common between n and n-1)

    // If n is not a power of 2:
    // n    = 10 (1010)
    // n-1  =  9 (1001)
    // -----------------
    // &    =  8 (1000)         (atleast 1 set bit will be common between n and n-1)

        return n>0 && (n&(n-1)) == 0;
    }
};


int main(){


    return 0;
};