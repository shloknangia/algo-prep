#include<iostream>
using namespace std;

class node{
public:
    long int data;
    node* next;
};

void addatfront(node* &head,int d){

	node* t = new node();
	t->data = d;
	t->next = head;
	head = t;
	
}

void addatend(node* &head,long int d){
    
    node* temp = new node();
    temp->data = d;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        node* t = head;
        while(head->next){
            head=head->next;
        }
        
        head->next = temp;
        head = t;
    }
    
}

void print(node* head){
    
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* input(long int n){
    
    node* head = NULL;
    while(n--){
        long int d;
        cin>>d;
        addatend(head,d);
        // print(head);
    }
    return head;
    
}

int length(node* head){
    
    int c=0;
    while(head){
        c++;
        head = head->next;
    }
    return c;
}

void shift(node* &head,int p){
    
    if(p!=0){
        int len = length(head);
        p = p%len;
        node* t = head;
        for(int i=0;i<len-p-1;i++){
            t=t->next;
        }
        
        node* t2 = t->next;
        node* t3 = t->next;
        t->next = NULL;
        while(t2->next){
            t2=t2->next;
        }
        t2->next = head;
        head = t3;
    }
    
    
    
}

int main() {
    
    long int n;
    cin>>n;
    
    node* head = input(n);
    int p;
    cin>>p;
    shift(head,p);
    
    print(head);
    
	return 0;
}
