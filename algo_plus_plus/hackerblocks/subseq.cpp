#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subseq(char *input,char *output,vector<string> &v,int i,int j){
    
    if(input[i] == '\0'){
        output[j] = '\0';
        string s(output);
        v.push_back(s);
        // cout<<output<<endl;
        return;
    }
    
    output[j] = input[i];
    subseq(input,output,v,i+1,j+1);
    
    
    subseq(input,output,v,i+1,j);
    
}


int main() {
    
    int n;
    cin>>n;
   char s[n][20],o[n][20];
   
    for(int i=0;i<n;i++){
    	vector<string> v;
        cin>>s[i];
        subseq(s[i],o[i],v,0,0);
        sort(v.begin(),v.end());
         for(int i=0;i<v.size();i++){
	        cout<<v.at(i)<<endl;
	    }
    }
//    for(int k=0;k<n;k++){
//	    sort(v[k].begin(),v[k].end());
//	    for(int i=0;i<v[k].size();i++){
//	        cout<<v[k].at(i)<<endl;
//	    }
//    }

    return 0;
    
}

