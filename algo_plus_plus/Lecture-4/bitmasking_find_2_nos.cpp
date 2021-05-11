#include<iostream>
using namespace std;


void findNumbers(int a[],int n){

    int x = 0;
    for(int i=0;i<n;i++){
        x = x^a[i];
    }

    /// xor is not zero, so atleast 1 set bit
    int pos=0;
    int ans = x;

    while(x>0){
        if(x&1){
            break;
        }
        pos++;
        x = x>>1;
    }

    ///Mask
    int mask = 1<<pos;
    int no1 = 0;
    for(int i=0;i<n;i++){
        if(mask&a[i]){
            no1 = no1^a[i];
        }
    }
    cout<<no1<<endl;
    int no2 = ans^no1;
    cout<<no2<<endl;

}

int main(){
    int a[] = {6,1,7,5,1,6,2,2};
    int n  = sizeof(a)/sizeof(int);

    findNumbers(a,n);

return 0;
}
