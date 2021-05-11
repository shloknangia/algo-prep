#include<iostream>
using namespace std;


void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
}

int main(){

    int x = 1;
    int &y = x;
    y++;

    cout<<y<<endl;
    cout<<x<<endl;

    int a = 10,b=12;
    swap(a,b);
    cout<<a<<" and "<<b;

}
