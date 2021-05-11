#include<iostream>
using namespace std;

///Kadane's algo
int maxSubarraySum(int a[],int n){
    int cs = 0,ms=0;

    for(int i=0;i<n;i++){

        cs += a[i];
        if(cs<0){
            cs = 0;
        }
        ms = max(ms,cs);

    }
    return ms;
}

int main(){
    int a[] = {1,-2,3,4,-1,6,7,-5,8,-10};
    int n = sizeof(a)/sizeof(int);

    cout<<maxSubarraySum(a,n);

}
