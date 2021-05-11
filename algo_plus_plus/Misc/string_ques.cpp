#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
cin.get();
string *s = new string[n];
string max;
int m = 0;
//for getline we need to take n+1
for(int i=0;i<n;i++){
	getline(cin,s[i]);
}
for(int i=0;i<n;i++){
	
	if(s[i].size() > m){
		max = s[i];
		m = s[i].size();
	}

}


	cout<<max;
	

return 0;    
}

