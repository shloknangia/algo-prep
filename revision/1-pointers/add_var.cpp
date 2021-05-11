#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{	// & returns address of variable
	int x = 10;
	cout<< &x<<endl;

	int y = 10.3;
	cout<< &y <<endl;

    // does not work for char(exeption)
    // because of operator overloading for << when cout gets (char *) i.e. &ch
    // if we use &ch -> returns value at that address

	char ch = 'A';
	cout<< (void *)&ch<< endl;
    // to get address need to use (void *)
    // explicit typecasting from char* to void *


	return 0;
}
