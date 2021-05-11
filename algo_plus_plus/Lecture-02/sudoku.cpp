#include<iostream>
#include<cmath>
using namespace std;

void print(int mat[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(int mat[][10],int i,int j,int no,int n){
    ///Row
    for(int x=0;x<n;x++){
        if(mat[i][x]==no){
            return false;
        }
    }

    ///Col
    for(int x=0;x<n;x++){
        if(mat[x][j]==no){
            return false;
        }
    }

    ///Subgrid
    int rn = sqrt(n);

    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==no){
                return false;
            }
        }

    }
    return true;
}

bool solveSudoku(int mat[10][10],int i,int j,int n){
    ///Base Case
    if(i==n){
        ///Print the matrix.
        print(mat,n);
        return true;
    }
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }
    ///Skip the blue cell
    if(mat[i][j]!=0){
            return solveSudoku(mat,i,j+1,n);
    }
    /// White Cell.
    for(int no=1;no<=n;no++){
        if(canPlace(mat,i,j,no,n)){
            mat[i][j] = no;

//            print(mat,n);
//            cout<<endl;

            bool solveHuiKya = solveSudoku(mat,i,j+1,n);
            if(solveHuiKya){
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}


int main(){
    int mat[10][10] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    int n=9;
    print(mat,n);
    cout<<endl;
    solveSudoku(mat,0,0,n);


return 0;
}
