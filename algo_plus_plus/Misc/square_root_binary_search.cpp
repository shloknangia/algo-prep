#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int p;
	cin>>p;
	float ans=0.0;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		a[i] = i;
	}
	int s=0,e=n-1;
	
	while(s<=e){
		int mid = (s+e)/2;
		if((a[mid]*a[mid]) == n){
			ans = a[mid];
		}
		if((a[mid]*a[mid]) >= n){
			e = mid-1;
		}
		if((a[mid]*a[mid]) <= n){
			ans = a[mid];
			s = mid+1;
		}
	}
	
	
	//floating part
	float inc = 0.1;
	for(int place =1;place<=p;place++){
		while(ans*ans<=n){
			ans += inc;
		}
		ans = ans-inc;
		inc = inc/10;
	}
	
	
	
	cout<<ans<<endl;
	return 0;
}
