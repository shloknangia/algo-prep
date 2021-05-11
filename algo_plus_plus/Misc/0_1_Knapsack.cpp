#include<iostream>
using namespace std;

int findprofit(int w[],int p[],int n,int W){
	
	if(n==0 || W==0){
		return 0;
	}
	int inc = 0,exc = 0;
	if(w[n-1]<=W){
		inc = p[n-1]+findprofit(w,p,n-1,W-w[n-1]);
		// if we have infinite items then we take (n) in above function call instead of (n-1)
	}	
	exc = findprofit(w,p,n-1,W);
	//not here
	return max(inc,exc);
}

int bottomupDP(int wt[],int p[],int n,int W){
	int dp[100][100] = {0};
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0 || w==0){
				dp[i][w] = 0;
			}
			int inc = 0,exc = 0;
			if(wt[i-1]<=w){
				inc = p[i-1] + dp[i-1][w-wt[i-1]];
				//for infinite items remaining items will be (i) instead of (i-1)
			}
			exc = dp[i-1][w];
			
			dp[i][w] = max(inc,exc);
		}
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
		
	}
	return dp[n][W];
}


int main(){
//	int w[] = {2,7,3,4};
//	int p[] ={5,20,20,10};
	int w[] = {2,2,3,1};
//	int p[] = {5,20,20,10};
	int p[] = {5,20,100,30};
	int n = 4;
//	int W = 11;
	int W = 5;
	cout<<findprofit(w,p,n,W)<<endl;
	cout<<bottomupDP(w,p,n,W)<<endl;
	return 0;
}
