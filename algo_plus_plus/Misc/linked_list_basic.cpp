#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:	
	int data;
	node* next;
	node(int d):data(d),next(NULL){}
	
	
	//recursive call, will be deleted while coming back 
	//use delete a to delete whole linked list
	~node(){
		if(next!=NULL){
			delete(next);
		}
	}
	
	
};

int lengthofll(node* head){
	int c=0;
	while(head){
		head = head->next;
		c++;
	}
	return c;
}



node* midpointofll(node* head){
// length /2

//	temp = head;
//	int c=0,co=0;
//	c = lengthofll(head);
//	
//	while(head && co<=(c/2)){
//		head = head->next;
//		co++;
//	}
	
	
	//2 pointer approach
	
	node* a = head;
	node* b = head->next;
	while(b && b->next){
		a=a->next;
		b = b->next->next;
	}
	
	return a; 
	
	
	
}

node* findelementRecursively(node* head,int n){
	
	if(head == NULL){
		return NULL;
	}
	
	else if(head->data==n){
		return head;
	}
	else{
		findelementRecursively(head->next,n);
	}
}


void bubbleSortLL(node* &head){
	
	int l = lengthofll(head);
	node* t1 = head;
	node* t2 = head->next;
	for(int i=0;i<l;i++){
		
		node* current = head;
		node* prev = NULL;
		
		while(current!=NULL && current->next!= NULL){
			
			if(current->data > current->next->data){
				//swapping
				
				if(prev == NULL){
					node* nextnode = current->next;
					current->next = nextnode->next;
					nextnode->next = current;
					head = nextnode;
					prev = nextnode;
				}
				else{
					//in middle
					node* nextnode = current->next;
					current->next = nextnode->next;
					nextnode->next = current;
					prev->next = nextnode;
					prev = nextnode;
					
				}
				
				
			}
			else{
				prev = current;
				current = current->next;
			}
		}
		
	}
}


void addatfront(node* &head,int d){
	//insert a element at front of linked list
	node* t = new node(d);
	t->next = head;
	head = t;
	
}

void addinmiddle(node* &head,int d,int p){
	if(p==0){
		addatfront(head,d);
		return;
	}
	else{
		//p less than equal to length
		int jump = 1;
		node* temp = head;
		while(jump<=p-1){
			temp = temp->next;
			jump++;
		}
	}
}


node* merge(node* a,node* b){
	
	//base
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	
	node* nh;
	if(a->data < b->data){
		nh = a;
		a->next = merge(a->next,b);
	}
	else{
		nh = b;
		b->next = merge(b,a->next);
	}
	return nh;
}


node* mergesort(node* &l){
	
//	int len = lengthofll(head);
	
	if(l==NULL || l->next==NULL){
		return l;
	}
	else{
		node* mid = midpointofll(l);
		node* a = l;
		node* b = mid->next;
		mid->next = NULL;
		if(l){
			a = mergesort(a);
			b = mergesort(b);
			return merge(a,b);
		}
}	
}


void reverse_it(node* &head){
	
	
	node* prev = NULL;
	node* current = head;
	node* nextnode;
	
	while(current){
		nextnode = current->next;
		current->next = prev;
		prev = current;
		current = nextnode;
		head = current;
	}
	head = prev;
}


node* reverse_rec(node* head){
	
	if(head == NULL || head->next == NULL)	{
		return head;
	}
	
	node* h = reverse_rec(head->next);
	node* temp = h;
	while(temp->next!=NULL){
		temp = temp->next;
	}//can also be head->next-next = head;
	temp->next = head;
	head->next = NULL;
	return h;
	
}




node* input(){
	node* head = NULL;
	int d;
	cin>>d;
	while(d!=-1){
		addatfront(head,d);
		cin>>d;
	}
	return head;
}

void delfront(node* &head){
	node* temp = head->next;
	delete head;
	head = temp;
}

void print(node* head){
	while(head){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<endl;
}


//so that we can write cout<<a;
//for cascading return type is ostream&
ostream& operator<<(ostream &o,node *a){
	
	while(a){
		o<<a->data<<" ";
		a = a->next;
	}
	return o;
	
}


istream& operator>>(istream &i,node* &a){
	a = input();
	return i;
}

int main() {

	node* head = input();


	print(head);
	node* a = reverse_rec(head);
	print(a);
	
	
	// to print whole ll we write own fxn operater overloading
//	cout<<a<<endl;
	return 0;
}
