#include<iostream>
using namespace std;

class Node;



class Node{
public:
    int data;
    Node* next;
    ///Init List in constructor
    Node(int d):data(d),next(NULL){}

    ~Node(){
        cout<<"Deleting node "<<data<<endl;
        if(next!=NULL){
                delete next;
        }

    }


};

void addAtFront(Node* &head,int d){
    ///Insert a element at the front of the LL
    Node *t = new Node(d);
    t->next = head;
    head = t;
}
void addIndle(Node* &head,int d,int p){

    if(p==0){
        addAtFront(head,d);
        return;
    }
    else{
        ///P is less than equal to length - Check
        int jump=1;
        Node*temp  = head;
        while(jump<=p-1){
            temp = temp->next;
            jump++;
        }
        Node* n = new Node(d);
        n->next = temp->next;
        temp->next = n;
        return;
    }


}

Node*takeInput(){

    Node*head = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        addAtFront(head,d);
        cin>>d;
    }
    return head;
}
void deleteFront(Node*&head){
    Node* temp = head->next;
    delete head;
    head = temp;
}

int length(Node*head){
    int len=0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

void bubbleSort(Node*&head){

    int n = length(head);
    for(int i=0;i<n-1;i++){

        ///Pairwise Swapping
        Node*current = head;
        Node*prev = NULL;

        while(current!=NULL&&current->next!=NULL){
            if(current->data > current->next->data){
                ///Swapping
                if(prev==NULL){
                    Node*nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    head = nextNode;
                    prev = nextNode;


                }
                else{
                    ///Middle
                    Node*nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;
                    prev->next = nextNode;
                    prev = nextNode;
                }



            }
            else{
                prev = current;
                current = current->next;
            }



        }


    }




}

Node* searchElement(Node*head,int element){
        if(head==NULL){
            return NULL;
        }
        ///Otherwise ?
        if(head->data==element){
            return head;
        }
        else{
            return searchElement(head->next,element);
        }
}

Node* midPoint(Node*head){
    Node* slow = head;
    Node* fast =head->next;

    while(fast&&fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void print(Node*head){
    while(head){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<endl;
}
ostream& operator<<(ostream &os,Node *a){

    print(a);
    return os;
}
istream& operator>>(istream&is,Node*&a){
    a = takeInput();
    return is;
}

Node* merge(Node* a,Node *b){
    ///Base Case
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    ///Otherwise !
    Node* nh;
    if(a->data < b->data){
        nh = a;
        a->next = merge(a->next,b);
    }
    else{
        nh = b;
        b->next = merge(a,b->next);
    }
    return nh;

}

Node* mergeSort(Node*l){
    ///Base Case
    if(l==NULL || l->next==NULL){
        return l;
    }
    ///Rec Case
    Node* mid = midPoint(l);

    Node*a = l;
    Node*b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}
void reverse(Node* &head){
    Node*current = head;
    Node*prev = NULL;
    Node*next;

    while(current!=NULL){
            ///Save the next node
        next = current->next;
        ///Make current node point to prev
        current->next = prev;

        ///Update prev & current
        prev = current;
        current = next;

    }
    head = prev;
}
///Rev Using Recursion
Node* recReverse(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Rec Reverse

    Node* chotaHead = recReverse(head->next);
    Node*temp = chotaHead;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return chotaHead;
}

Node* recReverse2(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Rec Reverse

    Node* chotaHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}


int main(){
    /*
    Node* head = takeInput();
    Node*tail = NULL;

    print(head);
    print(head);

    addIndle(head,4,3);
    print(head);

    bubbleSort(head);
    print(head);
    */
    /*
    Node* a = takeInput();
    Node*b = takeInput();

    cout<< a << endl<<b<<endl;
     a= merge(a,b);
    cout<<a<<endl;

    delete a;
    */

    Node *l;
    cin>>l;
    l=mergeSort(l);
    cout<<l;

    l = recReverse2(l);
    cout<<l<<endl;




    return 0;
}
