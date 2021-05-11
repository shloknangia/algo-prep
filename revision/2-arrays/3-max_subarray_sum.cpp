#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{	

    // Maximum Sub Array sum

    // eg: -4 1 3 -2 6 2 -1 4 -7
    // max sum is 13 for [1 3 -2 6 2 -1 4]

    int n;
    cin>>n;

    int a[n] = {0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // P1 -- time consuming as 3 nested loops ~ N^3
    // generate sums for all subarrays
    // finding largest of N sums
/*
    int maxsum = 0, csum = 0, l =-1, r = -1;// l and  r to keep tract of sub array with max sum

    for(int i=0;i<n;i++){ // start
        for(int j=i;j<n;j++){ // end
            csum = 0;
            for(int k=i;k<=j;k++){ // to traverse subarray(i,j)
                // cout<<a[k]<<", ";
                csum += a[k];
                // maxsum = max(csum, maxsum);
                if(csum> maxsum){
                    maxsum = csum;
                    l = i;
                    r = j;
                }
            }
            cout<<csum<<endl;
        }
    }

    cout<< maxsum<<endl<<l+1<<"to "<<r+1<<endl;
*/

    // P2: cumulative sum - 2 loops ~ (N + N^2)
    // preprocess the array and create cumulative sum array
    // where csum[i] = csum[i-1]+a[i]
/*
    int csum[n] = {0};
    csum[0] = a[0];
    for(int i=1;i<n;i++){ // N times
        csum[i] = csum[i-1] + a[i];
    }

    int maxsum = 0, cursum = 0, l =-1, r = -1;
    for(int i=0;i<n;i++){ // N^2
        for(int j=i;j<n;j++){ 
         int cursum = 0;
            cursum = csum[j] - csum[i-1];
                
            if(cursum> maxsum){
                maxsum = cursum;
                l = i;
                r = j;
            }
        }
    }
    cout<< maxsum<<endl<<l+1<<"to "<<r+1<<endl;
*/

    // P3: Kadane's Algorithm ~ O(N) - 1 loop
    // we dont need to generate all subbarrays 
    // input n: 9
    // input a: -4 1 3 -2 6 2 -8 -9 4
    // output ms: 10

    int cs = 0, ms = 0; // current sum and (max sum so far)

    for(int i=0;i<n;i++){
        // add element to cs
        cs += a[i];

        // if at any point cs becomes -ve make it 0
        // cs = max(cs, 0);
        if(cs<0){
            cs = 0;
        }

        // store max sum so far to ms
        ms = max(cs, ms);
    }

    cout<< ms;


	return 0;
}


