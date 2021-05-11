#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void combination(string a[10],char *input,char *output, int i){
	if(input[i] == '\0'){
		output[i] = '\0';
		cout<<output<<endl;
		return;
	}
	int digit = input[i] - '0';
	for(int k=0;k<a[digit].size();k++){
		output[i] = a[digit][k];
		combination(a,input,output,i+1);
	}
	
}


int main(){
	string a[10] = {
		" ",
		".+@$",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
	
	
	
	char input[10];
	gets(input);
	char output[10];
	combination(a,input,output,0);
	return 0;
}





//
//
//void keypad(string table[],char n[],char output[],int i){
//    if(n[i] == '\0'){
//        output[i] = '\0';
//        cout<<output;
//        return;
//    }
//    
//    for(int k=0;k<table[i].size();k++){
//        output[i] = table[i][k];
//        keypad(table,n,output,i+1);
//    }
//    
//    
//    
//    
//}
//
//int main() {
//string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
//
//char n[10],output[10];
//gets(n);
//keypad(table,n,output,0);
//return 0;
//
//    
//}

