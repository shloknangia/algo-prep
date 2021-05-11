#include<iostream>
using namespace std;
void print(char a[10][10],int n){
	
	int sr =0,er = n-1;
    int sc = 0,ec = n-1;
    int j=0;
    char symbol;
    
    while(sr<=er && sc<=ec){
        
        if(j%2==0){
        	symbol = 'O';
		}
		else	symbol = 'X';
        
        for(int i=sc;i<=ec;i++){
            a[sr][i] = symbol;
        }
        sr++;
        
        for(int i=sr;i<=er;i++){
            a[i][ec] = symbol;
        }
        ec--;
        
        if(er>=sr){
        for(int i = ec;i>=sc;i--){
            a[er][i] = symbol;
        }
        er--;
        }
        
        if(ec>=sc){
            for(int i=er;i>=sr;i--){
                a[i][sc] = symbol;
            }
            sc++;
        }
        
        j++;
    }
	
}

int main(){
	
int n;
cin>>n;
char a[10][10];
print(a,n);


for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
}
	/*
	00	01 	02	03	04
	10	11	12	13	14	
	20	21	22	23	24	
	30	31	32	33	34
	40	41	42	43	44
	
	*/
	
	return 0;
}
