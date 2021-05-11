#include <iostream>
using namespace std;

bool issubsetsum(int a[],int n){
    
    int last = (1<<n) - 1;
    for(int i=0;i<=last;i++){
        int no = i;
        int j = 0;
        int sum = 0;
        bool flag = false;
        while(j<n){
            if(no&1){
                sum += a[j];
                flag = true;
            }
            no = no>>1;
            j++;
        }
        if(sum == 0 && flag){
            // cout<<i<<endl;
            return true;
        }
        
    }
    return false;
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
        if(issubsetsum(a,n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
    
}

