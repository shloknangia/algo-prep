#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calculate(int p,int f){
    
    int dp[p+1][f+1] = {0};
    
    for(int i=0;i<=p;i++){
        for(int j=0;j<=f;j++){
            
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(i==1){
                dp[i][j] = j;
            }
            else if(j==1){
                dp[i][j] = 1;
            }
            
            else{
                
                dp[i][j] = INT_MAX;
                
                for(int x=1;x<=j;x++){
                    
                    int ans = 1 + max(dp[i][j-x],dp[i-1][x-1]);
                    dp[i][j] = min(dp[i][j],ans);
                }
            }
            
        }
    }
    
//	for(int i=0;i<=p;i++){
//	    for(int j=0;j<=f;j++){
//	        cout<<dp[i][j]<<" ";
//	   }
//	   cout<<endl;
//	}

    return dp[p][f];
	
}


int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        int p,f;
        cin>>f>>p;
        cout<<calculate(p,f)<<endl;
        // cout<<eggDrop(p,f);
        
    }

    return 0;    
}

