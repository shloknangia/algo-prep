#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Arrays

    //Declare + initialize
    int a[10] = {1,2,3};//[max size]
    // if initialized then number in firat 3 and 0 in all
    // else garbage value in all
    // a[10] = {0} -> 0 in all

    for(int i=0;i<10;i++){
        cout<<a[i]<<" ,";
    }
    cout<<endl;
    // input elements
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ,";
    }

    //update
    for(int i=0;i<10;i++){
        a[i] = a[i] * a[i];
    }

    //reverse
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<a[10-i-1]<<" ,";
    }

	return 0;
}


