#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // * -> dereference operator
    // multiplication- binary operator
    // pointer valiable
    // dereference any address (reverse of &)

    int x = 10;
    int* xptr = &x;

    cout<< x <<endl; //10
    cout<< xptr <<endl;//0x6ffe14
    cout<< &x <<endl;//0x6ffe14
    cout<< *xptr <<endl;//10
    cout<< *(&x) <<endl;//10
    cout<< *(xptr) +1 <<endl;//11
    cout<< *(xptr+1) <<endl;// next address, garbage value

    cout<< *(&xptr) <<endl;//0x6ffe14 = xptr
    cout<< &(*xptr) <<endl;//0x6ffe14

    // ** -> pointer to a pointer ot double pointer
    int** xxptr = &xptr;
    cout<<xxptr<<endl;//0x6ffe08 - address of xptr
    cout<< &xptr<<endl;//0x6ffe08

	return 0;
}


