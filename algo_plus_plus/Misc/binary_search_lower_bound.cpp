#include<iostream>
using namespace std;


int lowerbound(int a[],int no,int s,int e){
	
	int result = -1;
	while(s<=e){
		int m = (s+e)/2;
		if(a[m] == no){
			result = m;
			//lower bound
			e = m-1;
		// for upperbound
//		s = m+1;
		}
		else if(a[m]>=no){
			e = m-1;
		}
		else{
			s = m+1;
		}
		
	}
	return result;
}
int upperbound(int a[],int no,int s,int e){
	
	int result = -1;
	while(s<=e){
		int m = (s+e)/2;
		if(a[m] == no){
			result = m;
			s = m+1;
		}
		else if(a[m]>=no){
			e = m-1;
		}
		else{
			s = m+1;
		}
		
	}
	return result;
}

int main(){

	int a[]	 = {1,2,2,2,2,4,5,5,6};
	int n = sizeof(a)/sizeof(int);
	
	int no;
	cin>>no;
	
	cout<<lowerbound(a,no,0,n-1);
	cout<<endl<<upperbound(a,no,0,n-1);
	
	return 0;
}
