#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	
	node(int d):data(d),left(NULL),right(NULL){	}
};

class LL{
	public:
		node* head;
		node* tail;
};


LL treeToLL(node* root){
	LL l;
	if(root == NULL){
		l.head = NULL;
		l.tail = NULL;
		return l;
	}
	else if(root->left == NULL && root->right == NULL){
		l.head == root;
		l.tail == root;
		return l;
	}
	else if(root->left!=NULL && root->right==NULL){
		LL leftLL = treeToLL(root->left);
		leftLL.tail->right = root;
		l.tail = root;
		l.head = leftLL.head;
	}
	else if(root->left==NULL && root->right!=NULL){
		LL rightLL = treeToLL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		
		LL leftLL = treeToLL(root->left);
		LL rightLL = treeToLL(root->right);
		
		leftLL.tail->right = root;
		l.head = leftLL.head;
		
		root->right = rightLL.head;
		l.tail = rightLL.tail;
		
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


node* insertInBst(node* &root,int data){
	if(root == NULL)	{
		root = new node(data);
		return root;
	}
	else{
		if(data<=root->data){
			root->left = insertInBst(root->left,data);
		}else{
			root->right = insertInBst(root->right,data);
		}
	}
	
	return root;
}

node* takeinput(){
	node* root = NULL;
	int data;
	cin>>data;
	while(data!=-1){
		root = insertInBst(root,data);
		cin>>data;
	}
	return root;
	
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


node* search(node* root,int key){
	if(root == NULL){
		return NULL;
	}
	if(root->data == key){
		return root;
	}
	else if(root->data > key){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}

node* arraytotree(int a[],int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	node* root = new node(a[mid]);
	root->left = arraytotree(a,s,mid-1); 
	root->right = arraytotree(a,mid+1,e);
	return root;
}

bool isBST(node* root,int minV = INT_MIN,int maxV = INT_MAX){
	if(root== NULL)
		retrun true;
	}
	
	
}

bool check(node* r1,node*r2){
	
	//2 more cases
	if(r1!=NULL && r2==NULL){
		return false;
	}
	if(r1->data == r2->data){
		if(check(r1->left,r2->left) && check(r1->right,r2->right)){
			return true;
		}
	}
	return false;
}

int main() {
    node *n = NULL;
	cin>>n;
    cout<<n<<endl;
    
    LL list = treeToLL(n);
    node* temp = list.head;
    while(temp!= NULL){
    	cout<<temp->data<<"->";
    	temp = temp->right;
	}
	
	
	int a[] = {1,2,3,4,5,6,7};
	node*  r = arraytotree(a,0,8);
    return 0;    
}

