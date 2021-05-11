#include<iostream>
using namespace std;


int* createArray(){
    int a[] = {1,2,3};
    cout<<"In Fun"<<endl;
     for(int i=0;i<3;i++){
        cout<<a[i]<<" ";
    }
    cout<<a<<endl;
    return a;
}


int main(){
    int *a = createArray();
    cout<<a<<endl;
    cout<<"In Main"<<endl;
    for(int i=0;i<3;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
