#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void spiral(int a[10][10],int m,int n){
		
		int startrow = 0,endrow = m-1;
		int startcol = 0,endcol = n-1;
	    while(startrow<=endrow && startcol <= endcol){
	    	//print start row
	    	for(int i=startcol;i<=endcol;i++){
	    		 cout<<a[startrow][i]<<" ";
			}
			startrow++;
			
			//print end col
			for(int i=startrow;i<=endrow;i++){
				cout<<a[i][endcol]<<" ";
			}
			endcol--;
						
			
			//print the bottom row
			if(startrow<=endrow){
			for(int i=endcol;i>=startcol;i--){
				cout<<a[endrow][i]<<" ";
			}
			endrow--;
		}
			
			
			//print the start col
			if(startcol<=endcol){
			for(int i=endrow;i>=startrow;i--){
				cout<<a[i][startcol]<<" ";
			}
			startcol++;
		}

		}
	
}


int main() {
	int a[10][10];
	int m,n;
	cin>>m>>n;
	int value=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j] = value++;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	spiral(a,m,n);
	
	
	
	return 0;
}
