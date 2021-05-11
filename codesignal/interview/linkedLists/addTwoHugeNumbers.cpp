// You're given 2 huge integers represented by linked lists. Each linked list element is a number from 0 to 9999 that represents a number with exactly 4 digits. The represented number might have leading zeros. Your task is to add up these huge integers and return the result in the same format.

// Example

//     For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
//     addTwoHugeNumbers(a, b) = [9876, 5434, 0].

//     Explanation: 987654321999 + 18001 = 987654340000.

//     For a = [123, 4, 5] and b = [100, 100, 100], the output should be
//     addTwoHugeNumbers(a, b) = [223, 104, 105].

//     Explanation: 12300040005 + 10001000100 = 22301040105.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};
//

long long int getNumFromLL(ListNode<int> * a){
    long long int sum = 0;
    while(a!=NULL){
        sum = sum*pow(10,4) + a->value;
        a = a-> next;
        cout<<sum<<"\t";
    }
    return sum;
}

ListNode<int> * createLLFromNum(long long int num){
    ListNode<int> *t = NULL;
    // int val = num%1000;
    // long int newnum;
    do{
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = num%10000;
        num /=10000;
        temp->next = t;
        t = temp;
    }while(num>0);
    return t;
}

ListNode<int> * rev(ListNode<int> *l){
    ListNode<int> *prev = NULL;
    ListNode<int> *temp = NULL;
    ListNode<int> *curr = l;
    ListNode<int> *next = curr->next;
    
    while (next!=NULL) {
        curr->next = prev;
        temp = next->next;
        next->next = curr;
        
        prev = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    
    // long long int num1 = getNumFromLL(a);
    // long long int num2 = getNumFromLL(b);
    
    // cout<< num1<<endl<<num2<<endl;
    
    // return createLLFromNum(num1+num2);
    
    ListNode<int> *r1 = rev(a);
    ListNode<int> *r2 = rev(b);
    ListNode<int> *list = NULL;
    ListNode<int> *head = NULL;
    int carry = 0;
    while(r1!=NULL && r2 !=NULL){
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = (r1->value + r2->value + carry)%10000;
        carry = (r1->value + r2->value + carry)/10000;
        cout<<temp->value<<"\t"<<carry<<endl;
        if(list!=NULL){
            list ->next = temp;
            list = temp;
            // temp->next = list;
        }
        else{
            list = temp;
            head = list;
        }
        // list = temp;
        r1 = r1->next;
        r2 = r2->next;
    }
    cout<<"r1"<<endl;
    while(r1!=NULL){
       ListNode<int> *temp = new ListNode<int>(0);
        temp->value = (r1->value + carry)%10000;
        carry = (r1->value + carry)/10000;
        cout<<temp->value<<"\t"<<carry<<endl;
        if(list!=NULL){
            list ->next = temp;
            list = temp;
            // temp->next = list;
        }else{
            list = temp;
            head = list;
        }
        
        r1 = r1->next;
    }
    
    cout<<"r2"<<endl;
    
    while(r2!=NULL){
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = (r2->value + carry)%10000;
        carry = (r2->value + carry)/10000;
        cout<<temp->value<<"\t"<<carry<<endl;
        if(list!=NULL){
            list ->next = temp;
            list = temp;
            // temp->next = list;
        }else{
             list = temp;
            head = list;
        }
        
        r2 = r2->next;
    }
    
    cout<<"C"<<endl;
    if(carry>0){
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = carry;
        if(list!=NULL){
            list ->next = temp;
            list = temp;
        }else{
             list = temp;
            head = list;
        }
    }
    
    return rev(head);
}
