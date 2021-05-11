#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// custom string tokenizer
char* mystrtok(char str[], char delim){ //take 1 delim for now

    // need static variable to store state for subsequent calls
    static char* input = NULL;
    
    // check if first call or subsequent call
    if(str != NULL){ // new string if not null
        input = str;
    }

    if(input == NULL){
        return NULL;
    }

    // need a dynamic variable
    char* output = new char[strlen(input)+1];// +1 is for null char(\0)
    // return word as dynamically allocated word array as cannot return static var

    // read work from input
    // store in output
    // return word till delim

    int i;
    for(i=0;input[i]!='\0'; i++){
        if(input[i]!=delim){
            output[i] = input[i]; /// if delim not found copy to output
        }
        else{ // delim found
            output[i] = '\0'; // close output var to return
            input = input + i +1; // move input to new position, start + current pos + 1(for next pos)
            return output; // return output
        }
    }

    // if loop ends , null found , string ended
    // return last word;
    output[i] = '\0';
    input = NULL; // no need to keep , put null for next call
    return output;

}

int main()
{	
    // string tokeniser - strtok
    // similar to split in js, but these need to be called multiple times
    // s = "Hi I an Coding", delim= " " (space)
    // output: { "Hi", "I", "am", "Coding"}
    // char* strtok(char* str, char* delimiters);
    // if more delim are assed all will be removed(no need to be together)
    // header: <cstring>
    // first call pass in the string as argument
    // in subsequent calls, function expects a NULL pointer
    // it stores the variable state of string in prev function call
    // output:  will return null if nothing to point

    char str[] = "Hi I am a student";
    char *ptr;
    cout<<"Inbuilt Tokeniser returns: "<<endl;
    ptr = strtok(str, " ");
    // cout<<ptr<<endl;

    /*
        ptr = strtok(NULL, " ");// ---> Next call , pass NULL
        // NULL means extract string from original string
    */

    while(ptr!=NULL){
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    // Implement custom string tokenizer

    cout<<"Custom Tokeniser returns: "<<endl;
    char newstr[] ="Hi I am a student";

    ptr = mystrtok(newstr, ' ');
    while(ptr!=NULL){
        cout<<ptr<<endl;
        ptr = mystrtok(NULL, ' ');
    }

	return 0;
}


