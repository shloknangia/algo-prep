#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//string findpair(int a[],int i,int sum,int n){
//    cout<<a[i]<<endl;
//   int p=0,q = n;
//   while(p<=q){
//       
//       if(a[p] + a[q] == sum && p!=i && q!=i){
//           p++;
//           q--;
//           string s = a[p] + " and " + a[q];
//           return s;
//       }
//       else if(a[p] + a[q] >sum){
//           q--;
//       }
//   }
//   
//    return NULL;
//}



void findtriplet(int a[],int n,int sum){
    
   for(int i=0;i<n-2;i++){
   		for(int j=i+1;j<n-1;j++){
   			for(int k=j+1;k<n;k++){
   				if(a[i]+a[j]+a[k] == sum){
   					cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
				   }
			   }
		   }
   }
}


int main() {
    
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int sum;
    cin>>sum;
    sort(a,a+n);
    findtriplet(a,n,sum);
    return 0;
}

