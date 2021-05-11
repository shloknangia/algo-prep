#include<iostream>
using namespace std;

void spiralPrint(int a[][10],int m,int n){

    int startRow=0,endRow = m-1;
    int startCol = 0, endCol = n-1;

    while(startRow<=endRow && startCol<=endCol){
        ///Print the start row
        for(int i=startCol;i<=endCol;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;

        ///Print the End Col
        for(int i=startRow;i<=endRow;i++){
            cout<<a[i][endCol]<<" ";

        }
        endCol--;

        if(endRow>=startRow){
        ///Print the bottom row
        for(int i=endCol;i>=startCol;i--){
            cout<<a[endRow][i]<<" ";
        }
        endRow--;
        }

        ///Print the start Col
        if(startCol<=endCol){
        for(int i=endRow;i>=startRow;i--){
            cout<<a[i][startCol]<<" ";
        }
        startCol++;
        }
    }



}


int main(){

    int a[10][10];
    int m,n;
    cin>>m>>n;

    int value = 1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j] = value++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    spiralPrint(a,m,n);
return 0;
}
