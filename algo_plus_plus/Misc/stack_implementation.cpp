#include<iostream>
#include "stack.h"
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	stack<int> s;
	for(int i=0;i<10;i++){
		s.push(i*i);
	}
	while(!s.isempty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
