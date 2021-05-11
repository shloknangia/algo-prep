#include<iostream>
using namespace std;

class node{
public:    
  int data;
  node* left;
  node* right;
};


node* insertInBST(node*root,int data){
    if(root==NULL){
        root = new node();
        root->data = data;
        return root;
    }
    else {
        if(data<=root->data){
            root->left = insertInBST(root->left,data);
        }
        else{
            root->right = insertInBST(root->right,data);
        }
    }
    return root;

}
node* takeInput(int n){

        node*root = NULL;
        while(n--){
            int data;
            cin>>data;
            root = insertInBST(root,data);
        }
        return root;

}

void printTree(node*root){
    if(root==NULL){
        return;
    }
    if(root->left){
        cout<<root->left->data<<" => ";
    }
    else{
        cout<<"END => ";
    }
    cout<<root->data;
    if(root->right){
        cout<<" <= "<<root->right->data;
    }
    else{
        cout<<" <= END";
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);

}

void insertduplicate(node* &root){
    if(root== NULL){
        return;
    }
    
    node* n = new node;
    n->data = root->data;
    n->left = root->left;
    n->right = NULL;
    root->left = n;
    
    insertduplicate(root->right);
    insertduplicate(root->left->left);
    
    
}
int main() {
    
    int n;
    cin>>n;
    node* root = takeInput(n);
    insertduplicate(root);
    printTree(root);
	return 0;
}
