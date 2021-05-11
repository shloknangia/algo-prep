#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll stringtoint(string a,ll m){
	ll ans = 0;
	for(int i=0;i<a.size();i++){
		
		ans = (ans*10)%m + (a[i]-'0');
		ans = ans%m;
	}
	return ans;
	
}


ll pow(ll a,ll b,ll m){
	
	if(b == 0){
		return 1;
	}
	
	ll x = pow(a,b/2,m);
	x = x%m;
	x = (x*x)%m;
	if(b%2 == 0){
		
		return x%m;
	}
	else{
		return (x*a)%m;
	}
	
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
    	string a,b;
        cin>>a>>b;
        
        ll x = stringtoint(a,mod);
        ll y = stringtoint(b,mod);
        ll ans = pow(x,y,mod);
        cout<<ans<<endl;
    }

    return 0;    
}

