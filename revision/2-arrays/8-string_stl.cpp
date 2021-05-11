#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// custom comparator
// based on length of strings
bool compare(string a, string b){
    return a.length()<b.length();
    // return a<b; // default functionality
}

int main()
{	

    // Sting class in STL
    // strings without char
    // header: <cstring>

    string s("Hello World");
    cout<<s<<endl;

    string s2 = "Way 2";
    cout<< s2<<endl;
    cout<< s2.length()<<endl;// gives no of chars

    // string input
    // need to use getline which inputs string object
    string s3;
    getline(cin, s3);
    cout<< s3<<endl;

    string arr[] = {"Appleeeeee", "manago", "guava"};
    for (int i = 0; i < 3; i++){
        cout<<arr[i]<<endl;
    }

    // sort this array, lexiographically
    // using inbuilt sort function - header: <algorithm>
    sort(arr, arr+3);
    
    for (int i = 0; i < 3; i++){
        cout<<arr[i]<<endl;
    }

    sort(arr, arr+3, compare);
    
    for (int i = 0; i < 3; i++){
        cout<<arr[i]<<endl;
    }


	return 0;
}


