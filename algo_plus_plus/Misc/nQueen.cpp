#include<iostream>
using namespace std;

bool canplace(int grid[][100],int i,int j,int N){
	//check for col
	for(int row = 0;row<i;row++){
		if(grid[row][j] == 1){
			return false;
		}
	}
	
	//check for top left diag
	int x=i,y=j;
	while(x>=0 && y>=0){
		if(grid[x][y] == 1){
		return false;
		}
		x--;
		y--;
	}
	
	//top right diag
	x=i,y=j;
	while(x>=0&&y<N){
		if(grid[x][y] == 1){
		return false;
		}
	x--;
	y++;
	}
	
	return true;
}


bool solvequeen(int grid[][100],int N,int i=0){

	//base case
	if(i==N){
		//print grid
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<(grid[i][j]== 1?"Q":"0");
			}
			cout<<endl;
		}
		return true;
	}
	
	//otherwise try to place queen at each position
	for(int j = 0;j<N;j++){
		if(canplace(grid,i,j,N)){
			grid[i][j] =1;
			bool queenRakhParen = solvequeen(grid,N,i+1);
			if(queenRakhParen == true){
				return true;
			}
			
			//backtrack
			grid[i][j] = 0;
		}
	}
	return false;
}


int main(){
	int n;
	cin>>n;
	int grid[100][100] = {0};
	solvequeen(grid,n);
	return 0;
}
