#include<iostream>
#include"vector_class.h"

using namespace std;

int main(){
	
	vector<int> v;
	
	for(int i=0;i<10;i++){
		v.push_back(i*i);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}
