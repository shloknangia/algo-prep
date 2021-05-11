#include<iostream>
#include<queue>
#include<cmath>
using namespace std;


class node{
public:
    int data;
    node*left;
    node*right;
    node(int d):data(d),left(NULL),right(NULL){}
};

void printTree(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" = ";
    if(root->left){
        cout<<root->left->data<<",";
    }
    if(root->right){
        cout<<root->right->data;
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);

}
node* insertInBST(node*root,int data){
    if(root==NULL){
        root = new node(data);
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
node* takeInput(){

        node*root = NULL;
        int data;
        cin>>data;


        while(data!=-1){

            root = insertInBST(root,data);
            cin>>data;
        }
        return root;

}
node* takeInputLevel(){
    int d;
    node*root = NULL;
    cout<<"Enter root data ";
    cin>>d;
    root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();

        int d1,d2;
        cout<<"Enter children of "<<f->data<<"  - ";
        cin>>d1>>d2;
        if(d1!=-1){
            f->left = new node(d1);
            q.push(f->left);
        }
        if(d2!=-1){
            f->right = new node(d2);
            q.push(f->right);
        }
    }
    return root;



}
void levelOrderOutput(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*f = q.front();
            q.pop();
        if(f==NULL){

            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< f->data<<" ";

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

istream& operator>>(istream& is,node*&root){
    root = takeInput();
    return is;
}
ostream& operator<<(ostream& os,node* root){
    levelOrderOutput(root);
    return os;
}
void preOrder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node*root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}






pair<int,bool> isBalanced(node*root){
    if(root==NULL){
        return make_pair(0,true);
    }

    pair<int,bool> left = isBalanced(root->left);
    pair<int,bool> right = isBalanced(root->right);

    int height = max(left.first,right.first)+1;
    if(abs(left.first - right.first) <= 1 && left.second && right.second){

        return make_pair(height,true);
    }
    else{
        return make_pair(height,false);
    }

}

node* search(node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }

}

class LL{
public:
    node*head;
    node*tail;
};

LL tree2LL(node*root){
    LL l;

    if(root==NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    else if(root->left==NULL && root->right==NULL){
        l.head = root;
        l.tail = root;
        return l;
    }

    else if(root->left!=NULL && root->right==NULL){
        LL leftLL = tree2LL(root->left);

        leftLL.tail->right  = root;
        l.tail = root;
        l.head = leftLL.head;
    }
    else if(root->right!=NULL && root->left==NULL){
        LL rightLL = tree2LL(root->right);

        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }
    else{
        LL leftLL = tree2LL(root->left);
        LL rightLL = tree2LL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;

    }
    return l;

}

node* arrayToTree(int a[],int s,int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = arrayToTree(a,s,mid-1);
    root->right = arrayToTree(a,mid+1,e);
    return root;
}

bool isBST(node*root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}



int main(){
    /*
    node*root = NULL;
    cin>>root;
    cout<<root;

    LL myList = tree2LL(root);
    node* temp= myList.head;
    while(temp!=NULL){
        cout<< temp->data <<"-->";
        temp = temp->right;
    }
    */

    int a[] = {1,2,3,4,5,6,7,8,9};

    node*root = arrayToTree(a,0,8);

    if(isBST(root)){
        cout<<"BST hai ";
    }
    else{
        cout<<"Nahi hai !";
    }


return 0;
}

