#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// pass by value
void inc(int a){
    a = a+1;
    cout<<"inside func "<<a<<endl;
}

// Pass by reference using pointers
void dec(int* a){ //as pointer is passed
    *a -= 1;
    cout<<"inside func dec "<<*a<<endl;
}

int main()
{	

    // Pass by reference using pointers

    int a = 10;
    inc(a);
    dec(&a); // passing address or a int pointer(int*)
    cout<<"inside main "<<a<<endl;
	return 0;
}


