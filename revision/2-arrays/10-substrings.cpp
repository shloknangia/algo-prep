#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void substrings(char* c){
    for(int i=0;c[i]!='\0';i++){ // start
        for(int j=i;c[j]!='\0';j++){ // end
            cout<<"{"<<i<<","<<j<<"}"; // just indexces
            // run for loop to traverse
        }
        cout<<endl;
    }
}


int main()
{	

    // Substring: any consecutive sub segment similar to sub array
    /*
        Input: abc,
        Output: 
        a
        b
        c
        ab
        bc
        abc
    */
    
    char c[] = "hello";
    substrings(c);

	return 0;
}


