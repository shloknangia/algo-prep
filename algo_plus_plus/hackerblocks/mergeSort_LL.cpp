#include<iostream>
using namespace std;

class node{
public:    
  int data;
  node* next;
};

void addatfront(node* &head,int d){
    
    node* t = new node();
    t->data = d;
    t->next = head;
    head = t;
}

node* takeinput(){
    node* head = NULL;
    int d;
    cin>>d;
    while(d--){
        int a;
        cin>>a;
        addatfront(head,a);
    }
    
    return head;
    
}

void print(node* head){
    while(head){
        cout<<head->data;
        head = head->next;
    }
}

int lengthLL(node* head){
    int count =0 ;
    while(head){
        head = head->next;
        count++;
    }
    return count;
}

node* midpoint(node* head){
    node* s = head;
    node* f = head->next;
    
    while(f && f->next){
    	s = s->next;
    	f = f->next->next;
	}
	return s;
}


node*  merge(node* a, node* b){
    
    if(a== NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node* newhead = NULL;
    if(a->data < b->data){
        newhead = a;
        a->next = merge(a->next,b);
    }
    if(a->data > b->data){
        newhead = b;
        b->next = merge(a,b->next);
        
    }
    return newhead;
}

node* mergeSort(node* head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node* mid = midpoint(head);
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;
    if(head){
        
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a,b);
    }
    
    
    
    
}

int main() {
    node* head = takeinput();
    
    head = mergeSort(head);
    print(head);
    
	return 0;
}
