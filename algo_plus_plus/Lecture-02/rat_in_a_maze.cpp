#include<iostream>
using namespace std;

bool ratInMaze(char maze[][10],int soln[][10],int i,int j,int m,int n){
    ///Base Case
    if(i==m&&j==n){

        soln[i][j] = 1;
        ///Print the Soln
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }

        return true;
    }
    ///Rec Case
    ///Assume the path goes through the current cell
    soln[i][j] = 1;

    if(j+1<=n && maze[i][j+1]!='X'){

        bool rastaMila = ratInMaze(maze,soln,i,j+1,m,n);
        if(rastaMila==true){
            return true;
        }
    }
    if(i+1<=m && maze[i+1][j]!='X'){

        bool rastaMila = ratInMaze(maze,soln,i+1,j,m,n);
        if(rastaMila==true){
            return true;
        }

    }
    ///Backtracking
    soln[i][j]=0;
    return false;
}


int main(){

    char maze[10][10] = {
            "0000XX",
            "00XX0X",
            "X000X0",
            "00X000"
    };

    int soln[10][10] = {0};
    int m = 3,n=5;
    ratInMaze(maze,soln,0,0,m,n);

return 0;
}
