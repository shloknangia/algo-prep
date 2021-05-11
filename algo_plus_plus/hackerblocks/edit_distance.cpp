#include<iostream>
using namespace std;

int operations(string a,int i,string b,int j){
    
    if(i==0 && j==0){
        return 0;
    }
    else if(i==0){
        return j;
    }
    else if(j==0){
        return i;
    }
    
    else if(a[i] == b[j]){
       return operations(a,i-1,b,j-1);
    }
    else{
        return 1 + min(operations(a,i-1,b,j-1),min(operations(a,i,b,j-1),operations(a,i	-1,b,j)));
    }
}


int operationsdp(string a,int m,string b,int n){
    
    int dp[2001][2001] = {0};
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            
            if(i==0 && j==0){
                dp[i][j] = 0;
            }
            
            else if(i==0){
                dp[i][j] = j;
            }
            
            else if(j==0){
                dp[i][j] = i;
            }
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]);
            }
            
        }
    }
    
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return dp[m][n];
    
}


int main() {
    
    string a,b;
    cin>>a>>b;
    
    int x = a.length();
    int y = b.length();
    
    cout<<operationsdp(a,x,b,y);
	return 0;
}
