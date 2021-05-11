#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//sieve of erato


void nthprime(bool prime[1000000],int ans[]){
	
	
	for(int t=0;t<1000000;t++){
		prime[t] = true;
	}
	
	for(int i = 2;i*i<=1000000;i++){
		
		if(prime[i]){
			
			for(int j=i*2;j<1000000;j+=i){
				prime[j] = false;
			}
			
		}
		
	}
	int k = 0;
	for(int i=2;i<1000000;i++){
		if(prime[i]){
			ans[k++] = i;
		}
	}
	
}


int main() {
    
    int t;
    cin>>t;
    
    bool prime[1000000];
    int ans[1000000];
    nthprime(prime,ans);
    while(t--){
        int n;
        cin>>n;
        
        cout<<ans[n]<<endl;
        
        
//        int i=2;
//	while(n){
////		cout<<i<<" "<<prime[i]<<endl;
//		if(prime[i++]){
//			n--;
//		}
		
	}
	cout<<i-1<<endl;
        
    }

return 0;    
}

