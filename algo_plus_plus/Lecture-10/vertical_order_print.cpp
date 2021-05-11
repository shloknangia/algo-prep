#include<bits/stdc++.h>
using namespace std;

#define um unordered_map<int, vector<int> >

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

void traverseTree(node*root,int d,um &m){
    if(root==NULL){
        return;
    }

    m[d].push_back(root->data);
    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
}




int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);

    root->right->left = new node(7);
    root->right->left->right = new node(8);
    root->right->right = new node(9);

    um m;

    traverseTree(root,0,m);

    ///Keys - min key to max key
    int min_key = -2;
    int max_key = +2;

    for(int key=min_key;key<=max_key;key++){

        ///Print the vector for key
        for(int i=0;i<m[key].size();i++){
            cout<< m[key][i]<<" ";
        }
        cout<<endl;
    }



return 0;
}
