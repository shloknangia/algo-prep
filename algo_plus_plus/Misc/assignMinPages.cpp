#include<iostream>
using namespace std;
//minimize max pages for each student

bool check(int p[],int m,int nos,int sum){
	int j=0;
	for(int i=0;i<nos;i++){
		int st =0;
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

int assignMinPages(int p[],int s,int e,int sum,int nos){
	int result =-1;
	int end = sum;
	while(s<=end){
		int m = (s+end)/2;
		int aaa = check(p,m,nos,sum);
//		cout<<s<<" "<<end<<" "<<m<<" "<<aaa<<endl;
			if(aaa){
				result = m;
				end = m-1;
			}
			else s = m+1;	
	}
	return result;
}
int main(){
	int pages[] = {10,20,30,40};
	int n = sizeof(pages)/sizeof(int);
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += pages[i];
	}
	
	int s;
	cin>>s;
	cout<<assignMinPages(pages,0,n,sum,s);
	
	return 0;
}
