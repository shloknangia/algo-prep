#include<iostream>
#include<cstring>
using namespace std;

void print(char s[],int start,int len){
//	cout<<"here";
	for(int i=start;i<start+len;i++){
		cout<<s[i];
	}
	
}

void longest_palindrome(char s[]){
	int len = strlen(s);
	int low,high;
	int start;
	int count =0;
//	cout<<"here";
	for(int i=1;i<len;i++){
		
		low = i-1;
		high = i;
		while(low>=0 && high<len && s[low] == s[high]){
			if(high-low+1>count){
//				cout<<low<<" "<<s[low]<<" "<<high<<" "<<s[high]<<endl;
				
				count +=2;
				start = low;
			}
			high++;
			low--;
		}
		low = i-1;
		high = i+1;
		while(low>=0 && high<len && s[low] == s[high]){
			if(high-low+1>count){
			
				count +=2;
				start = low;
			}
			high++;
			low--;
		}
	}
	print(s,start,count);
}

int main(){
	char s[] = "forgeeksskeegfor";
	longest_palindrome(s);
	return 0;
}
