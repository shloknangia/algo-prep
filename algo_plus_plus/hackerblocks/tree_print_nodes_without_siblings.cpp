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


void print(node* root){
    
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);
    int i=1;
    while(!q.empty()){
        
        node* t = q.front();
        q.pop();
        
        if(t == NULL){
        	if(s.size() == 1){
        		node* g = s.top();
        		s.pop();
        		cout<<g->data<<" ";
        		
			}
			else{
				while(!s.empty()){
					s.pop();
				}
			}
			
			
             
            if(!q.empty()){
                q.push(NULL);
            }
        }
        
        else{
        	s.push(t);
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        
       
    }
    
    
    
}

void print1(node* root){
	if(root->left == NULL && root->right == NULL){
		return;
	}
	if(root->left!=NULL && root->right == NULL){
		cout<<root->left->data<<" ";
		print(root->left);
	}
	else if(root->right!=NULL && root->left == NULL){
		cout<<root->right->data<<" ";
		print(root->right);
	}
	else{
		print(root->left);
		print(root->right);
	}
	
}
//50 true 12 true 18 true 50 false false false false true 20 false true 40 true 30 false false false
int main() {
    
    node* root = NULL;
    root = input();
    
    print1(root);
    
	return 0;
}
