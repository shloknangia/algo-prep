#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int x  = 10;
	int x2  = 101;
	// Pointers- variable that stores address of another variable
	// to store the address of variable i.e. &x
	// written as: int* ptr (datatype* variablename)
	
	//declare
	int* y = &x; // declaration + initialization

	// OR
	int* y2; // declare (will be garbage if not initilized), recommended to store 0 if nothing 
	y2 = &x2; // initialize

	// avoid mismmatch like
	// char* ch = &x;
	// if int stored in char* the when we try to read values it will read just 1 byte i.e. size of char instead of all 4 bytes

	// size of pointer variable

	int a = 10; // size: 4 bytes
	char b = 'A'; // size: 1 byte

	// same for both as thay are addresses
	int* aptr = &a; // 4 bytes or 8 bytes
	char* bptr = &b; // 4 bytes or 8 bytes


	int* xptr;
	xptr = &x;

	// should be same i.e. address of x
	cout<< &x <<endl; //0x6ffdf4
	cout<< xptr << endl;//0x6ffdf4

	// Re-assign another address
	xptr = &x2;
	cout<< &x2 <<endl; //0x6ffdf0
	cout<< xptr << endl;//0x6ffdf0

	return 0;
}

