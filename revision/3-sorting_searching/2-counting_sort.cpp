#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Counting Sort
    // less time in average case, but not everytime
    // eg: 3 5 2 6 1 4 3
    // make freq array and count ooccurence or each


    int a[] = {1, 3,4,2,7 ,8};
    int n = sizeof(a)/ sizeof(int);
    
   

    for(int i=0;i<6;i++){
        cout<<a[i]<<", ";
    }

	return 0;
}


