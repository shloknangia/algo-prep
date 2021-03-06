// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

// This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

// Example

//     For

// grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
//         [4, 6, 5, 8, 7, 9, 3, 2, 1],
//         [7, 9, 8, 2, 1, 3, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]

// the output should be
// sudoku(grid) = true;

//     For

// grid = [[1, 3, 2, 5, 4, 6, 9, 2, 7],
//         [4, 6, 5, 8, 7, 9, 3, 8, 1],
//         [7, 9, 8, 2, 1, 3, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]

// the output should be
// sudoku(grid) = false.

// The output should be false: each of the nine 3 × 3 sub-grids should contain all of the digits from 1 to 9.

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> v){
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        if(v[i] != i+1){
            return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<int>> grid) {
    // check row
    for(auto row: grid){
        if(!isValid(row)) return false;
    }
    
    //check col
    for(int i=0;i<grid.size();i++){
        vector<int> col;
        for(int r = 0;r<grid.size();r++){
            col.push_back(grid[r][i]);
        }
        if(!isValid(col)) return false;
        
    }
        
    //check block
    for(int x = 0;x<grid.size()-3;x+=3){
        for(int y=0;y<grid.size()-3;y+=3){
            
            vector<int> l;
            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    l.push_back(grid[i][j]);
                }
            }
            if(!isValid(l)) return false;
        }
    }
    return true;
}


bool sudoku(std::vector<std::vector<int>> grid) {
    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 9; i++) {
            int crow = 0, ccol = 0, cgrid = 0;
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == k) crow++;
                if (grid[j][i] == k) ccol++;
                if (grid[j/3 + 3*(i/3)][j%3 + 3*(i%3)] == k) cgrid++;
                
                cout<<"k: "<<k<<endl;
                cout<<"row: "<<i<<"\t"<<j<<endl;
                cout<<"col: "<<j<<"\t"<<i<<endl;
                cout<<"row: "<<j/3 + 3*(i/3)<<"\t"<<j%3 + 3*(i%3)<<endl<<endl;
                
                if (crow == 2 || ccol == 2 || cgrid == 2) return false;
            }
        }
    }
    return true;
}

