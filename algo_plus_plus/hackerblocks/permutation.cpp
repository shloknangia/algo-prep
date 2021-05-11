#include <iostream>
using namespace std;


void print(char a[],int i=0){
    if(a[i] == '\0'){
        cout<<a<<endl;
        return;
    }
    for(int k = i;a[k]!='\0';k++){
        swap(a[k],a[i]);
        print(a,i+1);
        swap(a[k],a[i]);
    }
    
}

int main() {
    char a[20];
    
    cin.getline(a,20);
    print(a);
    return 0;
}

