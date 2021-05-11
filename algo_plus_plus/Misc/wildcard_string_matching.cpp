#include<iostream>
#include<cstring>
using namespace std;

bool ismatched(char str[],char pat[],int m,int n){
    bool dp[m+1][n+1] = {false};
    dp[0][0] = true;
    
    if(m==0){
        return n==0;
    }
    
    for(int j=1;j<=n;j++){
        if(pat[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        }
        
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(pat[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            
            else if(pat[j-1] == '?' || str[i-1] == pat[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
    
}


int main() {
    
    char str[1000];
    char pat[1000];
    
    cin>>str>>pat;
    
    if(ismatched(str,pat,strlen(str),strlen(pat))){
        cout<<"MATCHED";
    }
    else{
        cout<<"NOT MATCHED";
    }
	return 0;
}
