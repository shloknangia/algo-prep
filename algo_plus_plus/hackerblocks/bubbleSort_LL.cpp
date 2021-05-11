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
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int length(node* head){
	int c=0;
	while(head){
		head = head->next;
		c++;
	}
	return c;
}

void bubbleSort(node* &head){
    
    node* current = head;
    node* nextnode = current->next;
    node* prev;
  
    int l1 = length(head);
    int l2 = l1;
    while(l1--){
        current = head;
        nextnode = current->next;
        while(nextnode!=NULL){
            if(current->data > nextnode->data){
                // cout<<current->data<<"  "<<nextnode->data<<endl;
                if(current == head){
                   
                    current->next = nextnode->next;
                    nextnode->next = current;
                    prev = nextnode;
                    head = prev;
                    nextnode = current->next;
                }
                else{
                current->next = nextnode->next;
                nextnode->next = current;
                prev->next = nextnode;
                prev = nextnode;
                nextnode = current->next;
                }
            }
            else{
                // cout<<current->data<<"  "<<nextnode->data<<endl;
                prev = current;
                current = nextnode;
                nextnode = current->next;
            }
            
        }
        // print(head);
        
    }
  
}




int main() {
    node* head = takeinput();
    
    
    bubbleSort(head);
    print(head);
    
	return 0;
}
