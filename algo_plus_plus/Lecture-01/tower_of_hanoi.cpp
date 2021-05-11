#include<iostream>
using namespace std;


void toh(int n,char src,char help,char dest){
    ///Base Case
    if(n==0){
        return;
    }

    ///Rec Case
    toh(n-1,src,dest,help);
    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest;
    cout<<endl;
    toh(n-1,help,src,dest);

}

int steps(int n){
    if(n==0){
        return 0;
    }
    else{
        return 2*steps(n-1) + 1;
    }
}

int main(){

    int n;
    cin>>n;
    toh(n,'A','B','C');
    cout<<steps(n)<<endl;
    int ans = (1<<n) - 1;
    cout<<ans;
return 0;
}
