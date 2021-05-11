#include<iostream>
using namespace std;

void subArray(int n,int a[],int o[],int k){
	
	for(int i=0;i<n-k+1;i++){
		int max = a[i];
		for(int j=i;j<i+k;j++){
			if(a[j]>max){
				max = a[j];
			}
		}
		o[i] = max;
	}
	
}

int main(){
	
	int n;
	cin>>n;
	int *a = new int[n];
	int *o = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		o[i] = 0;
	}
	
	int k;
	cin>>k;
	
	
	subArray(n,a,o,k);
	int h = sizeof(o)/sizeof(o[0]);
	for(int i=0;i<n-k+1;i++){
		cout<<o[i]<<" ";
	}
	return 0;
	
}
