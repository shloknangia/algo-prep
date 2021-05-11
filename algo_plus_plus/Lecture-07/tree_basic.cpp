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

node* takeInput(){
    int data;

    cin>>data;
    node*n = NULL;

    if(data!=-1){
        n = new node(data);
        n->left = takeInput();
        n->right = takeInput();
    }
    return n;
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
    root = takeInputLevel();
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

int countNodes(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(node*root){
    if(root==NULL){
        return 0;
    }

    return 1 + max(height(root->left),height(root->right));
}

int updateTreeWithSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int temp = root->data;

    int leftSum = updateTreeWithSum(root->left);
    int rightSum = updateTreeWithSum(root->right);

    root->data = leftSum + rightSum;

    return temp + root->data;
}
///
class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    int op1 = left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    p.diameter = max(op1,max(op3,op2));
    p.height = 1 + max(left.height,right.height);

    return p;


}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));

}

pair<int,int> maxSum(node*root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> left  = maxSum(root->left);
    pair<int,int> right = maxSum(root->right);

    int inc = root->data + left.second + right.second;
    int exc = max(left.first,left.second) + max(right.first,right.second);

    return make_pair(inc,exc);
}

void mirrorTree(node*root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);

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



int main(){

    node*root = NULL;
    cin>>root;
    cout<<root;

    cout<<endl;
    preOrder(root);

    cout<<endl;
    inOrder(root);

    cout<<endl;
    postOrder(root);
    cout<<endl;

    cout<<"Count is "<<countNodes(root)<<endl;
    cout<<"heigt is "<<height(root)<<endl;
    cout<<"Diameter is "<<diameter(root)<<endl;
    cout<<"Fast Diameter is "<<fastDiameter(root).diameter<<endl;

    pair<int,int> ans  = maxSum(root);
    cout<<max(ans.first,ans.second)<<endl;

    bool isB = isBalanced(root).second;
    if(isB){
        cout<<"Class Over";
    }
    else{
        cout<<"Not yet Over";
    }


return 0;
}
