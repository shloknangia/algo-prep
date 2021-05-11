#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0){
        return 1;
    }
    ///Rec Case
    int smallPower = power(a,b/2);

    if(b&1){
            return a*smallPower*smallPower;
    }
    else{
        return smallPower*smallPower;
    }
}

int main(){

    cout<<power(3,4)<<endl;
}
