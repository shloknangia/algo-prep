#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateArr(char* c, int k){
    int i = strlen(c);
    while(i>=0){
        c[i+k] = c[i--];
    }
    // cout<<c<<endl;
    int newi = strlen(c);
    int j = newi-k;
    int start = 0;
    while(j<newi){
        c[start++] = c[j++];
    }
    c[newi-k] = '\0';

    cout<<c<<endl;
}


int main()
{	

    // Rotate chars by Key
    // Input: array, key
    // Input: Hello
    // Output: loHel

    char c[] = "hello";
    int key = 2;
    rotateArr(c, key);

	return 0;
}


