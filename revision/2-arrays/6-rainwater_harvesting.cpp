#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Rainwater trapping , hackerblock problem
    // find max water we can save bt buildings
    // Input
    // n - no of buildings
    // height of n buildings
    // Output: units of water saved

    /*
    Input:
        10
        0 2 1 3 0 1 2 1 2 1
    Outut: 
        5
    */


   // at every point water is stored bt max height to left and right of that building
   // min(left max of i, right max of i) - height of i
   // precompute left and right highest for each

   int n;
   cin>>n;
   int h[n] = {0};
   int left[n] = {0};
   int right[n] = {0};
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    left[0] = h[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1], h[i]);
    }

    right[n-1] = h[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1], h[i]);
    }

    /* 
        // to display
        for(int i=0;i<n;i++){
            cout<<left[i]<<",";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<",";
        }
        cout<<endl;
    */
    
    int water = 0;
    for(int i=0;i<n;i++){
        water += min(left[i], right[i]) - h[i];
    }

    cout<< water;

	return 0;
}


