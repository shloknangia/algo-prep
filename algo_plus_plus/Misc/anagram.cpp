#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isanagram(string a,string b){
	int n = a.length();
	int m = b.length();
	
	if(n != m){
		return false;
	}
//	to_lower(a);
	transform(a.begin(), a.end(), a.begin(), ::tolower);
//	b = tolower(b);

	int letters[1<<8] = {0};
	
	for(int i=0;i<n;i++){
		letters[a[i]]++;
	}
	for(int i=0;i<m;i++){
		if(b[i]>='A' && b[i]<='Z'){
			b[i] = b[i]-'A'+'a';
		}
		cout<<b[i]<<" ";
		letters[b[i]]--;
	}
	for(int j = 0;j<(1<<8);j++){
		if(letters[j]!=0){
			return false;
		}
	}
	return true;
}

int main(){
	
	string a,b;
	cin>>a>>b;
	
	if(isanagram(a,b)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	
	return 0;
}
