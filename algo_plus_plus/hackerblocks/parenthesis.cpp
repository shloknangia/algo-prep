#include<iostream>
#include<stack>
using namespace std;
int main() {
    
    stack<char> s;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        
        // s.push(a[i]);
        if(a[i] == '('){
            // cout<<"push"<<endl;
            s.push(a[i]);
        }
        else{
            // cout<<"pop"<<endl;
            s.pop();
        }
    }
    // cout<<s.size();
    if(s.empty()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    
	return 0;
}
