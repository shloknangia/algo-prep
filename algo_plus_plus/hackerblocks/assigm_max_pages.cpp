#include<iostream>
#define ll long long int;
using namespace std;
//minimize max pages for each student

bool check(ll p[],ll m,ll nos,ll sum){
	ll j=0;
	for(ll i=0;i<nos;i++){
		ll st =0;
		while(st+p[j]<=m && p[j]!=0)
		{st += p[j];
//		cout<<p[j];
			sum -= p[j];
			j++;
			
		}
//		cout<<endl;
	}
	if(sum>0){
		return 0;
	}
	else return 1;
}

ll assignMinPages(ll p[],ll s,ll e,ll sum,ll nos){
	ll result =-1;
	ll end = sum;
	while(s<=end){
		ll m = (s+end)/2;
		ll aaa = check(p,m,nos,sum);
//		cout<<s<<" "<<end<<" "<<m<<" "<<aaa<<endl;
			if(aaa){
				result = m;
				end = m-1;
			}
			else s = m+1;	
	}
	return result;
}
ll main(){
	
	ll sum = 0;
	
	ll n;
	cin>>n;
	ll *pages = new ll[n];
	ll s;
	cin>>s;
	for(ll i=0;i<n;i++){
		cin>>pages[i];
	}
	
	
	for(ll i=0;i<n;i++){
		sum += pages[i];
	}
	
	cout<<assignMinPages(pages,0,n,sum,s);
	
	return 0;
}
