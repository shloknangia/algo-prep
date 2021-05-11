#include<iostream>
using namespace std;

int knapsack(int wts[],int prices[],int N,int W){
    if(N==0||W==0){
        return 0;
    }

    ///Otherwise
    int i = N-1;

    ///Lelo
    int inc=0,exc=0;
    if(wts[i]<=W){
        inc = prices[i] + knapsack(wts,prices,N,W-wts[i]);
    }
    ///Chod do mat lo
    exc = knapsack(wts,prices,N-1,W);

    return max(inc,exc);
}

int dpKnapsack(int wts[],int prices[],int N,int W){

    int dp[100][100] = {0};

    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int i = n-1;


            int inc=0,exc=0;

            if(wts[i]<=w){
                inc = prices[i] + dp[n][w-wts[i]];
            }
            exc = dp[n-1][w];

            dp[n][w] = max(inc,exc);



        }

    }
    return dp[N][W];
}



int main(){
    int wts[] = {2,1,3,2};
    int prices[] = {1,3,5,2};

    cout<<knapsack(wts,prices,4,6)<<endl;
    cout<<dpKnapsack(wts,prices,4,6)<<endl;

return 0;
}
