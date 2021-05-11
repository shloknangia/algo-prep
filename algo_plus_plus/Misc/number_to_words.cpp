#include<iostream>
#include<cstring>
using namespace std;

void convert(char s[]){
	
	string ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
	string two_dig[] = {"","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
	string tens[] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	string hund[] = {"hundred","thousand"};
	
	int l = strlen(s);
	if(l==1){
			cout<<ones[*s-'0']<<" ";
			return;
		}
	while(*s!='\0'){
		
		if(l>=3){
			if(*s-'0'!=0){
				cout<<ones[*s-'0']<<" ";
				cout<<hund[l-3]<<" ";
			}
			l--;
		}
		else{
			
			if((*s-'0') == 1){
				int sum = (*s -'0') + (*(s+1)-'0');
				cout<<two_dig[sum]<<" ";
				return;
			}
			
			else{
				
				int i = *s-'0';
				cout<<tens[i]<<" ";
				s++;
				if(*s != 0){
					cout<<ones[*s-'0'];
				}
			}	
		}
			s++;
	}
	
	
}


int main(){
	char s[] = {"100"};
	convert(s);
	return 0;
}
