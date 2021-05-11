#include<iostream>
using namespace std;

class node{
public:	
	int data;
	node *next;
};

void add(node* &head,int d){
	
	node *t = new node();
	t->data = d;
	if(head == NULL){
		head = t;	
	}
	else{
		t->next = head;
		head = t;
	}
}

node* takeinput(int n){
	node* head = NULL;
	while(n--){
		int d;
		cin>>d;
		add(head,d);
	}
	return head;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

node* common(node* head1,node* head2){
	
	if(head1 == NULL || head2 == NULL){
		return NULL;
	}
	node* temp = head1;
	node* newhead = temp;
	while(head1!= NULL && head2 != NULL){
	//	cout<<head1->data<<" "<<head2->data<<"  ";
		if(head1->data == head2->data){
		//	cout<<"if"<<endl;
			temp->next->data = head2->data;
			head1 = head1->next;
			head2 = head2->next;
			temp = temp->next;
		}
		else if(head1->data < head2->data){
				head1= head1->next;
			//	cout<<"else if"<<endl;
		}
		else{
			head2 = head2->next;
		//	cout<<"else"<<endl;
		}
		
	}
	temp->next = NULL;
//	temp->next = common(head1,head2);
	return newhead->next;
	
}

int length(node *head){
	int count =0;
	while(head->next!=NULL){
		count++;
		head = head->next;
	}
	return count;
	
}

node* reverse(node* head){
	
	if(head == NULL && head->next == NULL){
		return NULL;
	}
	node* newhead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
	
	
}


node* order(node* head){
	
	node *newhead = head;
	node *end = head;
	int i = 1;
	while(end->next!=NULL){
		end = end->next;
	}
	node* rev = end->next;
	int l = length(head);
	for(;i<=l;i+=2){
		//cout<<head->data<<endl;
		node* temp = head->next;
		head->next = head->next->next;
		end->next = temp;
		end = end->next;
		end->next = NULL;
		head = head->next;
	}
	head->next = NULL;
	node *newlist = reverse(rev);
	head->next = newlist;
	return newhead;
	
}

int main(){
	/*
	node *head1 = new node();
	node *head2 = new node();
	int a,b;
	cin>>a>>b;
	head1 = takeinput(a);
	head2 = takeinput(b);
	
	print(head1);
	print(head2);
	
	node* res = common(head1,head2);
	print(res);*/
	
	//q 2
	
	node *head = new node();
	int n;
	cin>>n;
	head = takeinput(n);
	print(head);
	node *res = order(head);
	print(res);
	
	return 0;
}
