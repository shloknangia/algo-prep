#include <iostream>
using namespace std;

void wave(int a[10][10],int m,int n){
    
    int sr = 0,er =m-1;
    int sc = 0,ec = n-1;
    
    while(sr<=er && sc<=ec){
        
        for(int i=sr;i<=er;i++){
            cout<<a[i][sc]<<" ,";
        }
        sc++;
        
        if(sc<ec){
        for(int i = er;i>=sr;i--){
            cout<<a[i][sr]<<" ,";
        }
        sc++;
        }
        
    }
    
    cout<<"END";
    
}

int main() {
        
    int m,n;
    cin>>m>n;
    
    int a[10][10];
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    wave(a,m,n);

    return 0;
}

