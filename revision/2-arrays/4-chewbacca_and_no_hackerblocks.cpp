#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Chewbacca and number , hackerblock problem
    // input integer number x
    // inverse of number is (9-i)
    // transform number x to minimum possible positive number by inverting some(possibly zero) digits, num should not start with 0
    // 1<x< 10^18 (need to use long long)
    // Input: 4545
    // Output: 4444
    // Input: 9871
    // Output: 9121

    char a[20];
    cin>>a;

    int i = 0;
    if(a[i] == '9'){
        i++;
    }

    for(;a[i]!='\0';i++){
        int digit = a[i] - '0'; // char to int (ascii of digit - ascii of 0 = 55 - 50 = digit)
        if(digit>=5){
            digit = 9-digit;
            a[i] = digit + '0'; // back to char
        }
    }
    cout<<a<<endl;


	return 0;
}


