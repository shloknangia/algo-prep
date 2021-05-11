#include<iostream>
using namespace std;


int NN =0;

bool canplacequeen(int grid[12][12],int n,int i,int j){
    
    for(int a = 0;a<i;a++){
        if(grid[a][j] == 1){
            return false;
        }
    }
    
    int x=i,y=j;
    while(x>=0 && y>=0){
        if(grid[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    x = i;y=j;
    while(x>=0 && y<n){
        if(grid[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    
    return true;
    
}



bool nqueen(int grid[12][12],int n,int i=0){
    
    if(i==n){
        // for(int a=0;a<n;a++){
        //     for(int b=0;b<n;b++){
        //         cout<<grid[a][b];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return true;
    }
    
    
    for(int j=0;j<n;j++){
        if(canplacequeen(grid,n,i,j)){
            grid[i][j] = 1;
            
            
            // bool canweplace = 
            if(nqueen(grid,n,i+1)){
                NN++;
            }
            // if(canweplace){
            //     return true;
            // }
            
            grid[i][j] = 0;
            
        }
    }
    
    return false;
    
}



int main() {

    int n;
    cin>>n;
    
    int grid[12][12] = {0};
    nqueen(grid,n);
    cout<<NN;


	return 0;
}
