#include<iostream>
using namespace std;

int volume(int a[],int n){
    
    int *r = new int[n];
    int *l = new int[n];
    
    for(int i=0;i<n;i++){
        int max = a[i];
        for(int j = i;j<n;j++){
            if(a[j]>max){
                max = a[j];
            }
            
        }
        r[i] = max;
//        cout<<r[i]<<" ";
    }
//    cout<<endl;
    
    for(int i=n-1;i>=0;i--){
        int max = a[i];
        for(int j = i;j>=0;j--){
            if(max<a[j]){
                max = a[j];
            }
        }
        l[i] = max;
        
    }
    
//    cout<<"right: ";
     for(int i=0;i<n;i++){
         cout<<r[i]<<" ";
     }
     cout<<endl;
//     cout<<"left: ";
     for(int i=0;i<n;i++){
         cout<<l[i]<<" ";
     }
     cout<<endl;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans+min(l[i],r[i])-a[i];
    }
    return ans;
    
}




int main() {

    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<volume(a,n);
    
	return 0;
}
