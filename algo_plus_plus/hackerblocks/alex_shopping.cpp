#include <iostream>
using namespace std;

bool check(int a[],long int n,int A,int k){
    int c = 0;
	for(int i = 0;i<n;i++){
   		
   		if(A%a[i] == 0){
   			c++;
		}
   
    }
    if(c>=k){
        return true;
    }
    else return false;
    
}

int main() {
 
 int n;
 cin>>n;
 int *a = new int[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
     
 }
 int t;
 cin>>t;
//  sort(a,a+n);
 while(t--){
     
     int A,k;
     cin>>A>>k;
     if(check(a,n,A,k)){
         cout<<"Yes"<<endl;
     }
     else   cout<<"No"<<endl;
     
 }
 
 return 0;   
}

