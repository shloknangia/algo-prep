#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() 
{ 
	int a[] = {1,2,4,4,4,4,4,4,4,4,5,6,7,8,9,10};
	int n = sizeof(a)/sizeof(a[0]);
	vector<int> v;
	
	for(int i=0;i<n;i++){
		v.push_back(a[i]);
	}
	auto l = lower_bound(v.begin(),v.end(),4);
	auto u = upper_bound(v.begin(),v.end(),4);
	cout<<u-l<<endl;
//	reverse(v.begin(),v.end());
//	rotate(v.begin(),v.begin()+3,v.end());
	for(auto it = v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	return 0;
	 
} 
