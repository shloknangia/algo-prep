#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 191. Number of 1 Bits
// Easy

// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// Note:

//     Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
//     In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

 

// Example 1:

// Input: n = 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

// Example 2:

// Input: n = 00000000000000000000000010000000
// Output: 1
// Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

// Example 3:

// Input: n = 11111111111111111111111111111101
// Output: 31
// Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

 

// Constraints:

//     The input must be a binary string of length 32.

 
// Follow up: If this function is called many times, how would you optimize it?




class Solution {
    unordered_map<uint32_t, int> m;
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        if(m[n]) return m[n];
        while(n){
            if(n&1){
                count++;
            }   
            n >>=1;
        }
        m[n] = count;
        
        
        // while (n) {
        //     n &= (n - 1);
        //     count++;
        // }
        
//         n & (n - 1) drops the lowest set bit.

//         Eg:
//         Let's use n = 00101100 as an example. This binary representation has three 1s.

//         If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.

//         If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.

//         If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.

//         n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.
        
        
        return count;
        
    }
};


int main(){


    return 0;
};