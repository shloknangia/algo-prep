#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	
	node(int d):data(d),left(NULL),right(NULL){	}
};

class Pair{
	public:
		int height;
		int dia;
};


//Pair fast_dia(node* root){
//	
//	Pair p;
//	if(root == NULL){
//		p.height = 0;
//		p.dia =0;
//		return p;
//	}
//	
//	Pair left = fast_dia
//}

void mirror(node* root){
	
	if(root == NULL){
		return;
	}
	
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right); 
	
}


pair<int,bool> isbalanced(node* root){
	if(root==NULL){
		return make_pair(0,true);
	}
	
	pair<int,bool> left = isbalanced(root->left);
	pair<int,bool> right = isbalanced(root->right);
	
	  int height = max(left.first,right.first)+1;
	if(abs(left.first - right.first) <= 1 && left.second && right.second){
	
		return make_pair(height,true);
	}
	else{
		return make_pair(height,false);
	}
}


void printTree(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	if(root->left){
		cout<<root->left->data<<" , ";
	}
	if(root->right){
		cout<<root->right->data;
	}
	cout<<endl;
	
	printTree(root->left);
	printTree(root->right);
	
}

node* takeinput(){
	int data;
	cin>>data;
	node* n = NULL;
	if(data!=-1){
		n = new node(data);
		n->left = takeinput();
		n->right = takeinput();
	}
	return n;
	
}


node* takeinputLevel(){
	int d;
	node* root = NULL;
	cin>>d;
	root = new node(d);
	
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* f = q.front();
		q.pop();
		
		int d1,d2;
		cout<<"enter children of "<<f->data<<" ";
		if(d1!=-1)
		{f->left = new node(d1);
		q.push(f->left);
		}
		if(d2!=-1)
		{f->right = new node(d2);
		q.push(f->right);
		}
	}
	
	return root;
}

void printTreeLevel(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* f = q.front();
		q.pop();
		if(f == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ";
			
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right); 
			}
		}
	}

	
}

istream& operator>>(istream& is,node* &root){
	root = takeinput();
	return is;
}
ostream& operator<<(ostream& os,node* root){
	printTreeLevel(root);
	return os;
}

int count(node* root){
	
	if(root == NULL){
		return 0;
	}
	
	return 1 + count(root->left)+count(root->right);
}
//similarly find the sum oof all nodes
int height(node* root){
	if(root == NULL){
		return 0;
	}
	return 1 + max(height(root->left),height(root->right));
}

int replace_with_sum(node* root){//y value as only data is changed not address
	
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	int t = root->data;
	int leftSum = replace_with_sum(root->left);
	int rightSum = replace_with_sum(root->right);
	
	root->data = leftSum+rightSum;
	
	return (t  + root->data);
	
}

int diameter(node* root){
	if(root == NULL){
		return 0;
	}
	int opt1 = height(root->left)+height(root->right);
	int opt2 = diameter(root->left);
	int opt3 = diameter(root->right);
	
	return max(opt1,max(opt2,opt3));
}


void preorder(node* root){
	
	if(root == NULL){
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
	
}

void postorder(node* root){
	
	if(root == NULL){
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
	
}


void inorder(node* root){
	
	if(root == NULL){
		return;
	}
	
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
	
	
}

int main() {
    node *n = NULL;
	cin>>n;
    cout<<n<<endl;
//	replace_with_sum(n);
	cout<<diameter(n)<<endl;
    cout<<endl<<endl<<"preorder\n";
    preorder(n);
    cout<<endl<<"postorder\n";
    postorder(n);
    cout<<endl<<"inorder\n";
    inorder(n);
    
    
    mirror(n);
    cout<<endl<<n;
    return 0;    
}

