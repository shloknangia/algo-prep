#include<iostream>
#include<stack>
using namespace std;


void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {

    stack<int> s;
    char ch;


    cin>>ch;
    while(ch!='\n'){
        
        if(ch>=48 || ch<=57){
            int digit = ch-'0';
            s.push(digit);
        }
        
        else if(ch == '+'){
            
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int ans = a+b;
            s.push(ans);
            
        }
        else if(ch == '-'){
            
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int ans = a-b;
            s.push(ans);
            
        }
        else if(ch == '*'){
            
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int ans = a*b;
            s.push(ans);
            
        }
        else if(ch == '/'){
            
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int ans = a/b;
            s.push(ans);
            
        }
        print(s);
        cin>>ch;
    }

    int sol = s.top();
    cout<<sol;

	return 0;
}
