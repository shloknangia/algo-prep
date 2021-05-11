#include<iostream>
#include<stack>
using namespace std;

void stockspan(int a[],int o[],int n){
    
    stack<int> s;
    s.push(0);
    o[0] = 1;
   for(int i=1;i<n;i++){
       
       while(!s.empty() && a[s.top()]<=a[i]){
           s.pop();
       }
       
       if(s.empty()){
           o[i] = i+1;
       }
       
       else{
           o[i] = i-s.top();
       }
       
       s.push(i);
       
   }
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *a = new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int *o = new int[n];
        stockspan(a,o,n);
        for(int i=0;i<n;i++){
          cout<<o[i]<<" ";
        }
        cout<<endl;
    }
    
    
	return 0;
}
