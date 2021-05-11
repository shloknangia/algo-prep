#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxsum(int a[],int k,int n){
    
    deque<int> dq;
    
    int i;
    for(i=0;i<k;i++){
        
        while(!dq.empty() && a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
    }
    
    for(;i<n;i++){
        
        cout<<a[dq.front()]<<" ";
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() && a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        
    }
    cout<<a[dq.front()]<<" ";
    
}

int main() {
    
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    
    int *a =new int[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    
    maxsum(a,k,n);
    // int max=0;
    
    // for(int i=0;i<n-k+1;i++){
    //     max = a[i];
    //     for(int j=i;j<i+k;j++){
    //         if(a[j]>max){
    //             max = a[j];
    //         }
    //     }
    //     cout<<max<<" ";
    // }
    
 
    
	return 0;
}
