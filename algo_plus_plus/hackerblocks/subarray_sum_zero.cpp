#include <iostream>
using namespace std;

bool isSumZero(long int a[],int n){
    
    int cs = 0;
    bool f = false;
    for(int i=0;i<n;i++){
        cs = cs+a[i];
        if(cs == 0){
            f = true;
        }
    }
    
    return f;
}


int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long int *a = new long int[n];
        if(isSumZero(a,n)){
            cout<<"Yes";
        }
        else    cout<<"No";
    }

    return 0;
    
}

