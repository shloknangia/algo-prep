#include<iostream>
using namespace std;

class node{
public:
    long int data;
    node* next;
};


void addatend(node* &head,long int d){
	node* current = head;
	node* newnode = new node();
	newnode->data = d;
	while(current->next!=NULL){
		current = current->next;
	}
	newnode->next = newnode;
	if(head == NULL){
		head = newnode;
	}
	else{
		newnode->next = head;
		current->next = newnode;
//		head = newnode;
	}
	
//	return;
	
}



//void addatend(node* &head,long int d){
//    
//    node* temp = new node();
//    temp->data = d;
//    temp->next = NULL;
//    if(head == NULL){
//        head = temp;
//    }
//    else{
//        node* t = head;
//        while(head->next){
//            head=head->next;
//        }
//        
//        head->next = temp;
//        head = t;
//    }
//    
//}

void print(node* head){
    
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* input(){
    
    node* head = NULL;
    long int n;
    cin>>n;
    while(n!=-1){
        
        addatend(head,n);
        cin>>n;
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


void findcycle(node* head){
    
    if(head == NULL){
//        return head;
    }
    
    node* slow = head;
    node* fast = head;
    
    
    
    
}


int main() {
    
    node* head = input();
    
//    findcycle(head);
    
    
    print(head);
    
	return 0;
}
