#include<iostream>
#include<cstring>
using namespace std;


int main(){
    int n;
    cin>>n;

    cin.get();

    char input[100];
    char largest[100];
    int largest_len = 0;

    for(int i=0;i<n;i++){
        cin.getline(input,100);

        int l = strlen(input);

        if(l>largest_len){
            largest_len = l;
            strcpy(largest,input);
        }

    }

    cout<<largest<<endl;


}
