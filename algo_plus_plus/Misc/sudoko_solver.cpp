#include<iostream>
#include<math.h>
using namespace std;

void print(int mat[][10],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}


bool canplacenumber(int grid[][10],int i,int j,int n,int N){

//check for row
for(int row = 0;row<N;row++)	{
	if(grid[i][row] == n){
		return false;
	}
}
	
//check for col
for(int col = 0;col<N;col++)	{
	if(grid[col][j] == n){
		return false;
	}
}
	
	//subgrid
	//starting point of i,j = (i/sqrt(n))*sqrt(n),(j/sqrt(n))*sqrt(n)
	int rn  = sqrt(N);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	
	for(int x = sx;x<sx+rn;x++){
		for(int y = sy;y<sy+rn;y++){
			if(grid[x][y] == n){
				return false;
			}
		}
	}
return true;	
}




bool sudokoSolver(int grid[10][10],int i, int j, int N){
	if(i == N )	{
		
		print(grid,N);
		return true;
	}
	if(j==N){
		return sudokoSolver(grid,i+1,0,N);
	}
	
	//skip the blue cell
	if(grid[i][j] !	=0){
		return sudokoSolver(grid,i,j+1,N);
	}
	
	
	
	
	for(int k=1;k<=N;k++){
		if(canplacenumber(grid,i,j,k,N)){
			grid[i][j] = k;
			bool cansolvesudoko = sudokoSolver(grid,i,j+1,N);
			if(cansolvesudoko){
				return true;
			}
			grid[i][j] = 0;
		}
	}
	return false;
	
}



int main(){

int grid[10][10] = 
		{{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
int N = 9;	
print(grid,N);
cout<<endl;
	
sudokoSolver(grid,0,0,N);	
return 0;	
}
