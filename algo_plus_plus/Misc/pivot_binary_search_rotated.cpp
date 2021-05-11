#include<iostream>
using namespace std;

int search(int a[],int s,int e){

	while(s<=e){
	int mid = (s+e)/2;
	if(a[mid]>a[mid+1]){
		return mid;
	}
	if(a[mid]<a[mid-1]){
		return mid-1;
	}

	if(a[mid]>=a[s]){
		s=mid+1;
		}	
	if(a[mid]<=a[s]){
	e= mid-1;
		}
	}
	return -1;
}



int main(){
	
	int a[]	= {6,7,1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);
	cout<<a[search(a,0,n-1)];
	return 0;
}

