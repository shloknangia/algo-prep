#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void subseq(char input[],char output[],
	vector<string> &vs,
	int i=0,int j=0){
	//i for input, j for output
	//base
	if(input[i] == '\0'){
		output[j] = '\0';
//		cout<<output<<endl;
		string s(output);
		vs.push_back(s);
		return;
	}
	
	//rec
	//inc ith char
	
	output[j] = input[i];
	subseq(input,output,vs,i+1,j+1);

	
	//excl ith char
	subseq(input,output,vs,i+1,j);
}

int main(){
char input[] = "abc";
char output[10];
vector<string> vs;
subseq(input,output,vs);

// for sorted output
sort(vs.begin(),vs.end());
for(int i=0;i<vs.size();i++)
	cout<<vs.at(i)<<endl;

return 0;	
}
