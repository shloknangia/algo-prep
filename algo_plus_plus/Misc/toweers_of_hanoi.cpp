#include<iostream>
using namespace std;


void toh(int n, char src,char help,char dest)
{if(n == 0)
	return;
 
 toh(n-1,src,dest,help)	;
 cout<<"move"<<n<<"from"<<src<<"to"<<dest<<endl;
 toh(n-1,help,src,dest);
}

int steps(int n){
	if(n == 0) 
	return 0;
	else{
		return 2*steps(n-1)+1;
	}
}
int main()
{
	int n;
	cin>>n;
	toh(n,'A','B','C');
//	int ans = steps(n);
	 int ans = (1<<n)-1;
	cout<<ans;
	return 0;
	
}




//#include <iostream>
//using namespace std;
//
//
//void toh(int n, char source,char destination , char helper){
//    
//    
//    //base
//    if(n==0){
//        return;
//    }
//    
//    
//    toh(n-1,source,helper,destination);
//    cout<<"Moving ring "<<n<<" from "<<source<<" to "<<destination<<endl;
//    toh(n-1,helper,destination,source);
//}
//
//int main() {
//int n;
//cin>>n;
//toh(n,'A','B','C');
//
//    
//return 0;    
//}
