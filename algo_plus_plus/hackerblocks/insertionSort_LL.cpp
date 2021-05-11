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

node* insertionSort(node* head){
    
    
    node* newhead = NULL;
    int l = length(head);
    while(l--){
        
        node* newnode = new node();
        newnode->data = head->data;
        // cout<<newnode->data<<endl;
        newnode->next = NULL;
        
        
        if(newhead == NULL){
            newhead = newnode;
        }
        else{
            node* current = newhead;
            node* prev = NULL;
            while(current!= NULL){
                
                if(current->data > newnode->data){
                    
                    if(current == newhead){
                        
                        newnode->next = current;
                        newhead = newnode;
                    }
                    else{
                        newnode->next = current;
                        prev->next = newnode;
                        prev = prev->next->next;
                        
                    }
                    
                    break;
                }
                else{
                    prev = current;
                    current = current->next;
                }
            }
            if(current == NULL){
                prev->next = newnode;
            }
            
        }
        head = head->next;
        // print(newhead);
    }
    
    return newhead;
}



int main() {
    node* head = takeinput();
    
    
    head = insertionSort(head);
    print(head);
    
	return 0;
}
