#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//every element occurs twice except 2 elements find it


void find(int a[],int n){
	int x;
	for(int i=0;i<n;i++){
		x = x^a[i];
	}
//x is not zero so atleast 1 bit is set	
	int pos =0;
	int ans = x;
	while(x>0){
		if(x&1){
			break;
		}
		pos++;
		x = x>>1;
	}
	
	
	//mask
	int mask = 1<<pos;
	int no1 =0;
	for(int i=0;i<n;i++){
		if(mask&a[i]){
			no1 = no1^a[i];
		}
	}
	cout<<no1<<endl;
	int no2 = no1^ans;
	cout<<no2<<endl;
	
}
int main() {
	int a[] = {6,1,7,10,1,6,2,2};
	int n = sizeof(a)/sizeof(int);
	
	find(a,n);
	return 0;
} 
