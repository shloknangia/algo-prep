#include<iostream>
using namespace std;


void print(char *input,int i=0){
    ///Base Case
    if(input[i]=='\0'){
        cout<<input<<endl;
        return;
    }

    ///Rec Case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        print(input,i+1);
        ///Backtrack - Restore original array
        swap(input[i],input[j]);
    }

}

int main(){
    char input[10] = "abc";
    print(input);

return 0;
}
