#include<iostream>
using namespace std;

float squareRoot(int n,int p){

    float ans;
    ///Binary Search
    int s = 0,e = n;

    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            e = mid-1;
        }
        else{
            s = mid + 1;
            ans = mid;
        }
    }
    ///Floating Part
    float inc = 0.1;
    for(int place=1;place<=p;place++){

        while(ans*ans<=n){
            ans += inc;
        }

        ans = ans - inc;
        inc = inc/10;

    }

    return ans;
}

int main(){
    int no,p;
    cin>>no>>p;

    cout<<squareRoot(no,p)<<endl;


}
