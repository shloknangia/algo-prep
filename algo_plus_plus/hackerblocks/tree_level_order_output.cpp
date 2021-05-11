#include<iostream>
#include<queue>
using namespace std;

class node{
public:  
  int data;
  node* left;
  node* right;
    
};


node* input(){
    
    int value;
    string isleftchild,isrightchild;
//    cout<<"  value  ";
    cin>>value;
    node* n = new node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
//    cout<<"  leftchild  ";
    cin>>isleftchild;
    if(isleftchild == "true"){
    	n->left = input();
	}
//	cout<<"  rightchild  ";
	cin>>isrightchild;
	if(isrightchild == "true"){
		n->right = input();
	}

    return n;
    
}


void print(node* root){
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            
           cout<<endl;
           if(!q.empty()){
           	q.push(NULL);
		   }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
    
}

//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
int main() {
    node* root= NULL;
    root = input();
    
    print(root);
    
    
    
    
	return 0;
}
