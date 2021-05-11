#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void rotate(int ar[4][4]){
	int temp;
	for(int i=0;i<4;i++){
		for(int j=0;j<i;j++){
			swap(ar[i][j],ar[j][i]);
		}
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++){
			swap(ar[i][j],ar[i][3-j]);
		}
	}
}

int main() {
	
	int a[4][4] = {{1,2,3,4},
				 {5,6,7,8},
				 {9,10,11,12},
				 {13,14,15,16}};
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	rotate(a);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
