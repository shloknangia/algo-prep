#include<iostream>
using namespace std;

class node{
public:    
  long int data;
  node* next;
};

void addatend(node* &head,long int d){
    
    node* t = new node();
    t->data = d;
    t->next = NULL;
    if(head == NULL){
        head = t;
    }
    else{
        node* a = head;
        while(head->next){
            head=head->next;
        }
        head->next = t;
        head = a;
        
        
    }
    
   
}

node* takeinput(long int d){
    node* head = NULL;
    while(d--){
        long int a;
        cin>>a;
        addatend(head,a);
    }
    
    return head;
    
}

void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


node* merge(node* a,node* b){
    
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    
    node* newnode = NULL;
    if(a->data <= b->data){
        newnode = a;
        a->next = merge(a->next,b);
    }
    if(a->data > b->data){
        newnode = b;
        b->next = merge(a,b->next);
    }
    
    return newnode;
}




int main() {
    
    int t;
    cin>>t;
    
    
    while(t--){
        long int n1,n2;
        cin>>n1;
        node* head1 = takeinput(n1);
        print(head1);
        
        cin>>n2;
        node* head2 = takeinput(n2);
        print(head2);
        
        node* head = merge(head1,head2);
        
        print(head);
    }
    
	return 0;
}
