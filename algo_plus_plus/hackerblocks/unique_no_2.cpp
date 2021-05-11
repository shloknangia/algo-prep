#include<iostream>
using namespace std;

void find(int a[],int n){
    
    int s=0;
    for(int i=0;i<n;i++){
        s = s^a[i];
    }
    // cout<<s<<endl;
    int ans = s;
    int  p=0;
    while(s>0){
        if(s&1){
            break;
        }
        p++;
        s = s>>1;
    }
    
    int no1 =0,no2 = 0;
    int mask = 1<<p;
    for(int i = 0;i<n;i++){
        if(mask&a[i]){
            no1 = no1^a[i];
        }
    }
    no2 = no1^ans;
    
    cout<<min(no1,no2)<<" "<<max(no1,no2);
    
    
}


int main() {
    
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    find(a,n);
    
    
	return 0;
}
