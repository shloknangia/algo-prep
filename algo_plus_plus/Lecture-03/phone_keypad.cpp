#include<iostream>
#include<cstring>
using namespace std;

void phoneKeypad(string *m,char *input,char *output,int i=0,int j=0){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    if(input[i]=='1'||input[i]=='0'){
        return phoneKeypad(m,input,output,i+1,j);
    }

    int digit = input[i]-'0';
    for(int k=0;k<m[digit].size();k++){
            output[j] = m[digit][k];
            phoneKeypad(m,input,output,i+1,j+1);
    }
}

int main(){


    string s[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    char input[10];
    cin>>input;

    char output[10];
    phoneKeypad(s,input,output);



return 0;
}
