#include<iostream>
using namespace std;


bool ratinamaze(char maze[][1000],int sol[][1000],int i,int j,int n,int m){
    
    if(i==n && j==m){
        sol[i][j] = 1;
        for(int a=0;a<=n;a++){
           for(int b=0;b<=m;b++){
                cout<<sol[a][b]<<" ";
        }
        cout<<endl;
    }
        return true;
    }
    
    if(maze[i][j] == 'X'){
        return false;
    }
    maze[i][j] = 'X';
    
    //rec
    sol[i][j] = 1;
   
    if(j+1<=m && maze[i][j+1] != 'X'){
        
        bool isthereaway = ratinamaze(maze,sol,i,j+1,n,m);
        
        if(isthereaway){
            return true;
        }
        
    }
    if(i+1<=n && maze[i+1][j] != 'X'){
        
        bool isthereaway = ratinamaze(maze,sol,i+1,j,n,m);
        
        if(isthereaway){
            return true;
        }
        
    }
    
     
    
    sol[i][j] = 0;
    return false;
    
    
}


int main() {
    
    int N;
    int M;
    cin>>N>>M;
    char maze[1000][1000];
    
    int sol[1000][1000] = {0};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maze[i][j];
            sol[i][j] =0;
        }
    }
    
    
    int ans = ratinamaze(maze,sol,0,0,N-1,M-1);
    if(ans == false){
    	cout<<"-1";
	}
    
	return 0;
}
