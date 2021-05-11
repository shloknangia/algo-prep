#include<iostream>
#include<stack>
using namespace std;

void pushatbottom(stack<int> &s,int no){
	if(s.empty()){
		s.push(no);
		return;
	}
	
	//otherwise
	int t = s.top();
	s.pop();
	pushatbottom(s,no);
	s.push(t);
}

void reverse_stack(stack<int> &s){
	//base
	if(s.size() == 0){
		return;
	}
	
	//rec
	int top = s.top();
	s.pop();
	reverse_stack(s);
	pushatbottom(s,top);
}

void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
int main(){
	stack<int> s;
	
	for(int i=0;i<5;i++){
		s.push(i);
	}
	print(s);
	cout<<endl;  
	reverse_stack(s);
	print(s);
	return 0;
}


