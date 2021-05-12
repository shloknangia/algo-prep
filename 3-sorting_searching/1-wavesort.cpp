#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Wavesort
    // eg: 1 3 4 2 7 8
    // output: 
    // graph should be like this
    // \/\/\/
    // up down up down up down
    // soln: sort then merge like first last or swap adjacent elements
    // 1 2 3 4 7 8 -> 8 1 7 2 4 3 but sorting takes time

    // O(N) approach

    int a[] = {1, 3,4,2,7 ,8};
    int n = sizeof(a)/ sizeof(int);
    // for(int i=0;i<5;i+=2){
    //     if(a[i]<a[i+1]){
    //         swap(a[i],a[i+1]);
    //     }
    // }

    for(int i=0;i<n;i+=2){
        // check for left
        if(i>0 && a[i-1]>a[i]){
            swap(a[i],a[i-1]);
        }
        // check for right
        if(i<=(n-2) && a[i]<a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    for(int i=0;i<6;i++){
        cout<<a[i]<<", ";
    }

	return 0;
}


