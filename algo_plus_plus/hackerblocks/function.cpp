#include <iostream>
#include<cmath>
using namespace std;

int function(long int n){
    int sum = 0;
    
    if(n&1){
        return -1*(n>>1) - 1;
    }
    else{
        return n>>1;
    }
    
//     for(long int i=1;i<=n;i++){
//         if(i&1)
//             sum -= i;   
//         else
//             sum += i;
//             
//             cout<<sum;
//     }
//     return sum;
    
    
}

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {   long int n;
        cin>>n;
        cout<<function(n)<<endl;
    }
    
    return 0;
}



