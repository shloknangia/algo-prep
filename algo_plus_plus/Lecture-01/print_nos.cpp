#include<iostream>
using namespace std;

void printDec(int n){

    if(n==0){
        return;
    }
    cout<<n;
    printDec(n-1);

}

void printInc(int n){

    if(n==0){
        return;
    }

    printInc(n-1);
    cout<<n;
}
int main(){
    int n = 5;
    printInc(n);
    cout<<endl;
    printDec(n);

}
