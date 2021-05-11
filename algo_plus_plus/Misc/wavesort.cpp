#include<iostream>
using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void wavesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		if(i%2==0){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			
			}
		}
		else{
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		print(a,n);
	}
}

int main(){
	
	int a[] = {1,2,3,4,5,6,7,8,9,10};
//	{1,4,2,6,7,8,9};
	int n =sizeof(a)/sizeof(int);
	print(a,n);
	wavesort(a,n);
	print(a,n);
	return 0;
}
