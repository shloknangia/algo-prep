#include<iostream>
#include<cstring>
using namespace std;

void kreverse(char *a,int k){
	
	int l = strlen(a);
	int i = l-1;
	
	while(i>=0){
		a[i+k] = a[i];
		i--;
	}
	a[l+k] = '\0';
	
	int x = strlen(a)-1;
	int y = k-1;
	
	while(y>=0){
		a[y] = a[x];
		x--;y--;
	}
	a[l] = '\0';
	
}


int main(){
	char a[100];
	cin.getline(a,100);
	int k;
	cin>>k;
	kreverse(a,k);
	cout<<a;
	return 0;
}
