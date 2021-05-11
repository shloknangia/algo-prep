#include<iostream>
#include<cstring>

using namespace std;
#define ll long long int



ll a[1000005], prefix[1000005];

int main() {
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        memset(prefix,0,sizeof(prefix));
        ll sum = 0;
        prefix[0] = 1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum = sum+ a[i];
            sum %= n;
            sum = (sum+n)%n;
            prefix[sum]++;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            // cout<<prefix[i]<<" ";
            ll no = prefix[i];
            ans += (no*(no-1))/2;
        }
        // cout<<endl;
        cout<<ans<<endl;
        
    }
    
    
	return 0;
}
