#include<iostream>
using namespace std;

int mincoins(int coins[],int n,int amount){
	
	if(amount == 0){
		return 0;
	}
	int ans = INT_MAX;
	int newans;
	for(int i=0;i<n;i++){
		
		if(amount-coins[i]>=0){
			newans = mincoins(coins,n,amount-coins[i]);
		}
		ans = min(ans,newans+1);
	}
	return ans;
}

int mincoinsBU(int coins[],int n,int amount){
	
	int *dp = new int[amount];
	for(int i=1;i<=amount;i++){
		dp[i] = INT_MAX;
	}
	dp[0]=0;
	for(int r=1;r<=amount;r++){
		for(int i=0;i<n;i++){
			int newans ;
			if(r-coins[i]>=0){
				newans = dp[r-coins[i]];
			}
//			cout<<dp[r]<<" "<<newans<<endl;
			dp[r] = min(dp[r],newans+1);
			
		}
//		cout<<r<<" "<<dp[r]<<endl;
	}
	return dp[amount];	
}

int main(){

	int coins[] = {1,7,10};
	int n = 3;
	int amount = 22;
	
	int coins2[] = {1,2,5,10,50};
	
	cout<<mincoins(coins,n,amount)<<endl;
	cout<<mincoins(coins2,5,13)<<endl;
	
	cout<<mincoinsBU(coins,n,amount)<<endl;
	cout<<mincoinsBU(coins2,5,39)<<endl;
	
	

	return 0;
}
