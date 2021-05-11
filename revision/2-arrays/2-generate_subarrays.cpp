#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Sub Arrays
    // i-j of array and continous

    int N = 10;
    int a[N] = {1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<N;i++){ // start
        for(int j=i;j<N;j++){ // end
            for(int k=i;k<=j;k++){ // to traverse subarray(i,j)
                cout<<a[k]<<", ";
            }
            cout<<endl;
        }
    }

	return 0;
}


