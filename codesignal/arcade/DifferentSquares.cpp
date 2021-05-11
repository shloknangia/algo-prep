// Given a rectangular matrix containing only digits, calculate the number of different 2 × 2 squares in it.

// Example

// For

// matrix = [[1, 2, 1],
//           [2, 2, 2],
//           [2, 2, 2],
//           [1, 2, 3],
//           [2, 2, 1]]

// the output should be
// differentSquares(matrix) = 6.

// Here are all 6 different 2 × 2 squares:

//     1 2
//     2 2
//     2 1
//     2 2
//     2 2
//     2 2
//     2 2
//     1 2
//     2 2
//     2 3
//     2 3
//     2 1
#include<bits/stdc++.h>
using namespace std;

int differentSquares(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    if(m<2 ||n<2){
        return 0;
    }
    if(m ==2 && n==2){
        return 1;
    }
    
    vector<string> mem;
    for(int x = 0;x<=matrix.size()-2;x++){
        for(int y = 0;y<=matrix[0].size()-2;y++){
            
            //traverse
            string temp ="";
            for(int i=x;i<x+2;i++){
                for(int j=y;j<y+2;j++){
                    temp+=to_string(matrix[i][j]);
                }
            }
            // cout<<temp<<"\t";
            auto it = find(mem.begin(), mem.end(), temp);
            if(it==mem.end()){
                // cout<<"new";
                mem.push_back(temp);
            }
            // cout<<endl;
        }
    }
    return mem.size();

}
