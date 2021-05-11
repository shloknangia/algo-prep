#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<string,int> a,pair<string,int> b){
    
    if(a.second == b.second){
        return a.first<b.first;
    }
    
    else{
        return a.second>b.second;
    }
    
}

int main() {
    
    int sal;
    cin>>sal;
    int n;
    cin>>n;
    
    
    pair<string,int> emp[100000];
    
    for(int i=0;i<n;i++){
        cin>>emp[i].first>>emp[i].second;
    }
    
    sort(emp,emp+n,mycomp);
    
    for(int i=0;i<n;i++){
        if(emp[i].second>=sal){
            cout<<emp[i].first<<" "<<emp[i].second<<endl;
        }
    }
    
	return 0;
	
}
