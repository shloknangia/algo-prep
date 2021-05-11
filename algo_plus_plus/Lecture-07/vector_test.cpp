#include<iostream>
#include "Vector.h"
#include<cstring>
using namespace std;


int main(){

    Vector<string> v;

    for(int i=65;i<80;i++){
        v.push_back("Hello ");
    }


    for(int i=0;i<v.size();i++){
        cout<< v[i] <<endl;
    }


return 0;
}
