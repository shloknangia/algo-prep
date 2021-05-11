#include<iostream>
#include<cstring>
using namespace std;

void mask(char input[],int no){

    int i = 0;

    for( ; no>0; no>>=1){
        if(no&1){
            cout<<input[i];
        }
        i++;
    }
    cout<<endl;
}

int main(){
    char input[100];
    cin>>input;
    int n = strlen(input);

    for(int i=0;i< (1<<n) ; i++){
        mask(input,i);
    }

return 0;
}
