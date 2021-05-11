#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void readline(char *s,int n,char delim){
	int i=0;
	char ch = cin.get();
	while(ch!=delim){
		s[i] = ch;
		i++;
		if(i==n-1){
			break;
		}
		ch = cin.get();
	}
	s[i] = '\0';
}
int main() {
	char s[100];
	cin.getline(s,10);
//	,'$');
	//3argu where to stop
	
//	readline(s,10,'$');
	cout<<s<<endl;


/////////strings 

//	string s;
//	getline(cin,s);
//	cout<<s;
//	cout<<s[2];
//	cout<<endl<<s.length();
//



return 0;    
}

