#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
public:  
  int data;
  node* left;
  node* right;
};




node* input(){
    
    int d;
    cin>>d;
    node* n = new node();
    n->data = d;
    
    string leftchild,rightchild;
    cin>>leftchild;
    if(leftchild == "true"){
        n->left = input();
    }
    cin>>rightchild;
    if(rightchild == "true"){
        n->right = input();
    }
    
    
    return n;
}


void printzigzag(node* root){
    
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    int i=1;
    while(!q.empty()){
        
        node* t = q.front();
        q.pop();
        
        if(t == NULL){
        	if(i%2== 0){
        		while(!s.empty()){
        			node* g = s.top();
        			s.pop();
        			cout<<g->data<<" ";
				}
			}
             i++;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        
        else{
        	if(i%2 == 0){
        		s.push(t);
			}
        	else{
            	cout<<t->data<<" ";
            }
            
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        
       
    }
    
    
    
}


int main() {
    
    node* root = NULL;
    root = input();
    
    printzigzag(root);
    
	return 0;
}
