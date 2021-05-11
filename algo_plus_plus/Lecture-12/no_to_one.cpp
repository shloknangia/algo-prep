#include<iostream>
using namespace std;

int waysToOne(int n){
    if(n==1){
        return 0;
    }

    int op1,op2,op3;
    op1=op2=op3 = INT_MAX;

    if(n&1==0){
            op2 = waysToOne(n/2);
    }
    if(n%3==0){
           op3 = waysToOne(n/3);
    }
    op1 = waysToOne(n-1);

    return min(op1,min(op2,op3)) + 1;
}
void waysToOneBU(int n){
    int *dp = new int[n]{0};

    for(int i=2;i<=n;i++){
        dp[i] = INT_MAX;

        if(i%2==0){
            dp[i] = min(dp[i],dp[i/2]+1);
        }
        if(i%3==0){
            dp[i] = min(dp[i],dp[i/3]+1);
        }
        dp[i] = min(dp[i],dp[i-1]+1);
    }

}

int main(){

    cout<<waysToOne(10)<<endl;

}
