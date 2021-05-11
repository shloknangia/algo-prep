#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char* mystrtok(char *str,char delim){
	static char* input = NULL;
	if(str!=NULL){
		input = str;
	}
	
	if(input == NULL){
		return NULL;
	}
	
	char* output = new char[strlen(input)+1];
	int i;
	for(i=0;input[i]!='\0';i++){
		if(input[i]!=delim){
			output[i] = input[i];
		}
		else{
			output[i] = '\0';
			input += i+1;
			return output;
		}
	}
	
	output[i] = NULL;
	input = NULL;
	return output;
}

int main() {
	char input[100] = "HEY, THIS IS SOMETHING NEW";
	char *token = mystrtok(input,' ');
//	cout<<strtok(NULL," ");
//	cout<<strtok(NULL," ");
//	cout<<strtok(NULL," ");
	while(token!=NULL){
		cout<<token<<endl;
		token = mystrtok(NULL,' ');
	}

	
	return 0;
}
