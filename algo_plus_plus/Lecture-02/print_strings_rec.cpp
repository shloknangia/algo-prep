#include <iostream>
using namespace std;


void printStrings(char *input,char *output,int i=0,int j=0){
    // Base Case
    if(input[i]=='\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    
    //Rec Case - Two Options - Two calls
    // Take 1 character a time
    int digit = input[i]-'0';
    char ch =   64 + digit;
    output[j] = ch;
    printStrings(input,output,i+1,j+1);
    
    // Take 2nd Case - 2 char at time
    if(input[i+1]!='\0'){
        int secondDigit = input[i+1]-'0';
        int no = 10*digit + secondDigit;
        if(no<=26){
            ch = 64 + no;
            output[j] = ch;
            printStrings(input,output,i+2,j+1);
        }
    }
    
}


int main() {
    char input[] = "521";
    char output[100];
    printStrings(input,output);
    
    return 0;
}
