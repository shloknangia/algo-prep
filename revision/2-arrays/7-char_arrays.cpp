#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Character Arrays, 1 char = 1 byte
    // terminated by 'NULL' '\0'
    // cout starts with first(non NULL char) and reads till null char

    char a[] = {'1', '2', '3', '\0'}; // need to insert null in this type
    cout<<a<<endl;
    cout<<sizeof(a)<<endl;

    char b[] = "hello"; // no need to insert NULL in this type
    cout<<b<<endl;
    cout<<sizeof(b)<<endl;

    //Input char array

    // cin--- no space or tab only word
    // cin.get --- 1 char including special char
    // cin.getline -- if you need to store space line "hello world", paragraph

    char c[100];
    cin>>c; // input: hello world
    cout<<c; // prints: hello

    char d[100];
    cin.getline(d, 100,'.'); // input: hello world , (var, size, delimeter)
    cout<<d;// prints: hello world

    // 2D char array
    // char z[x][y] -> list of string, where x -> no of strings, y-> max size of each string

    char d2[][4] = {{'a','b','c','\0'}, {'d','e','f','\0'}};// may maynot have garbage so terminate with null
    cout<<d2[0][0]<<endl;
    cout<<d2[0]<<endl;// will print : (abcdef and garbage value), if not added null other wise just abc

    //OR
    char words[10][100] = {
        "Apple", "Banana"
    };

    // length : strlen(ch)
    // cin.ignore : to ignore enter after n

	return 0;
}


