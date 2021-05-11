#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int b[5];

int search(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

bool mycomp(int x,int y){
    
    int xx = search(b,5,x);
    int yy = search(b,5,y);
    if(xx != -1 && yy!=-1){
        return xx<yy;
    }
    else if(xx != -1){
        return true;
    }
    else if(yy != -1){
        return false;
    }
    else{
        return x<y;
    }
}

int main() {
    
    // int a[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int a[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 7, 5, 6, 9, 7, 5};
    
    // b[] = {2, 1, 8, 3};
    // b[0] = 2;
    // b[1] = 1;
    // b[2] = 8;
    // b[3] = 3;
    
    
     //b[] = {2, 1, 8, 3, 4};
    b[0] = 2;
    b[1] = 1;
    b[2] = 8;
    b[3] = 3;
    b[4] = 4;
    int n = sizeof(a)/sizeof(a[0]);
    sort(a,a+n,mycomp);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
	//code
	return 0;
}
