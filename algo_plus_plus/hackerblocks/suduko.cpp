#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool canplaceno(int grid[][10],int n,int i,int j,int k){
    
    for(int a=0;a<n;a++){
        if(grid[i][a] == k){
            return false;
        }
    }
    
    for(int b=0;b<n;b++){
        if(grid[b][j] == k){
            return false;
        }
    }
    
    int rn = sqrt(n);
    int newi = (i/rn)*rn;
    int newj = (j/rn)*rn;
    
    for(int x = newi;x<newi+rn;x++){
        for(int y=newj;y<newj+rn;y++){
            if(grid[x][y] == k){
                return false;
            }
        }
    }
    
    return true;
}


bool solve(int grid[10][10],int n,int i,int j){
    
    if(i==n){
        for(int l=0;l<n;l++){
            for(int t=0;t<n;t++){
                cout<<grid[l][t]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    
    if(j==n){
        return solve(grid,n,i+1,0);
    }
    
    
    if(grid[i][j] != 0){
        return solve(grid,n,i,j+1);
    }
    
    for(int k=1;k<=n;k++){
        if(canplaceno(grid,n,i,j,k)){
            grid[i][j] = k;
            bool canPlace = solve(grid,n,i,j+1);
            if(canPlace){
                return true;
            }
            grid[i][j] = 0;
        }
    }
    
    
    return false;
}


int main() {

    int n;
    cin>>n;
    int grid[10][10];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    solve(grid,0,0,n);
    
    

	return 0;
}@
