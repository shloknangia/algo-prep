#include<iostream>
using namespace std;
typedef long long int ll;


void merge(ll a[],ll s,ll mid,ll e){
    
    // ll *x = new ll[mid-s+1];
    // ll *y = new ll[e-mid];
    
    // for(int i=s;i<=mid;i++){
    //     x[i] = a[i];
    // }
    
    // for(int i=mid;i<=e;i++){
    //     y[i] = a[i];
    // }
    
    ll *c = new ll[e-s+1];
    
    
    ll i = s,j = mid+1;
    ll k = 0;
    
    while(i<=mid && j<=e){
        
        if(a[i] < a[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = a[j++];
        }
        
        
    }
    
    
    while(i<=mid){
        c[k++] = a[i++];
    }
    while(j<=e){
        c[k++] = a[j++];
    }
    
    for(ll i=s,j = 0;i<=e,j<e-s+1;i++,j++){
        a[i] = c[j];
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    
    
}


void mergesort(ll a[],ll s,ll e){
    
    if(s>=e){
        return;
    }
        ll mid = (s+e-1)/2;
        // cout<<"passed: ";
        // for(int i=s;i<=mid;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        mergesort(a,s,mid);
        // cout<<"passed: ";
        // for(int i=mid+1;i<=e;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
        
   
}


int main() {
    
    ll n;
    cin>>n;
    ll *a = new ll[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    
    mergesort(a,0,n-1);
    
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
	return 0;
}
