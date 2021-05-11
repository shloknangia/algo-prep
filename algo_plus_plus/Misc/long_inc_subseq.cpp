#include<iostream>
using namespace std;
//longest inc subseq

int lis(int a[],int n){
	int *dp = new int[n];
	
	for(int i=0;i<n;i++){
//		dp[i] = 1;
		dp[i] = a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
//			if(a[i]>a[j] && dp[i]< dp[j]+1){
//				dp[i] = dp[j]+1;
//			}
			if(a[i]>a[j] && dp[i] < a[i]+dp[j]){
				dp[i] = dp[j]+ a[i];
			}
		}
	}
	int max = 0;
	
	for(int i=0;i<n;i++){
		if(dp[i] > max)	{
			max = dp[i];
		}
	}
	return max;	
}

int main(){
//	int a[] = {5,6,2,3,4,1,9,9,8,9,5};
	int a[] = {1,101,2,3,100,4,5};
	int n = sizeof(a)/sizeof(int);
	cout<<lis(a,n);
	
	return 0;
}
