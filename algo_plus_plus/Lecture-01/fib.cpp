#include<iostream>
using namespace std;

int fib(int n){;
    // cout<<"n rec: "<<n<<endl;
    ///Base Case
    if(n==0||n==1){
        // cout<<"base "<<n<<endl;
        return n;
    }

    ///Rec Case
    int ans = fib(n-1) + fib(n-2);
    // cout<<"ans "<<ans<<endl;0 1 1 2 3 5 8 
    return ans;
}

int main(){
    cout<<fib(6);
    return 0;
}
