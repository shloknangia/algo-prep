#include<iostream>
using namespace std;


void find(int a[],int n){
    
    int res =0;
    for(int i=0;i<32;i++){
        
        int x,sum = 0;
       x = 1<<i;
       for(int j=0;j<n;j++){
        if(a[j]&x){
            sum++;
        }
       }
       
       
        if(sum%3){
            res = res|x;
        }
    }
    cout<<res;
    
}


int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    find(a,n);
    
	return 0;
}
