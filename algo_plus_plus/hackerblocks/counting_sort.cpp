#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define l long int


void counting_sort(long int a[],long int o[],long int n){

    l count[MAX];
    memset(count,0,sizeof(count));
    

    for(l i=0;i<n;i++){
        count[a[i]]++;
    }
    
    l sum = 0;
    for(l i=0;i<MAX;i++){
        // count[i] += count[i-1];
        sum = sum+count[i];
        count[i] = sum;
    }
    
    
    for(l i=0;i<n;i++){
        o[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    
    
    
}


int main() {
    
    l n;
    cin>>n;
    l *a = new l[n];
    for(l i;i<n;i++){
        cin>>a[i];
    }
    
    l *o = new l[n];
    
    
    counting_sort(a,o,n);
    
    for(l i;i<n;i++){
        cout<<o[i]<<" ";
    }
    
    
    
	return 0;
}
