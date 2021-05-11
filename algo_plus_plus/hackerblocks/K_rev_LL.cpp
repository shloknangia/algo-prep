#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
};


void addatend(node* &head,int d){
    
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

node* input(int n){
    
    node* head = NULL;
    // long int n;
    // cin>>n;
    while(n--){
        int d;
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


node* reverse(node* &head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
    
    
}


bool hasKnodes(node* head,int k){
	int l = length(head);
	if(l>=k){
		return true;
	}
	else{
		return false;
	}
	
}


node* reversek(node* head,int k){
     
     
    if(!hasKnodes(head,k)){
    	return reverse(head);
	}
     
     
    node* current = head;
    for(int i=0;i<k-1;i++){
        current = current->next;
         
	}
    node* newnexthead = reversek(current->next,k);
    current->next = NULL;
    node* newhead = reverse(head);
     
    node* temp = newhead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnexthead;
    return newhead;
}


int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        node* head = input(n);
        node* newhead = reversek(head,k);
        print(newhead);
    }
	return 0;
}
