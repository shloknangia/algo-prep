// Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.

// Given a singly linked list of integers, determine whether or not it's a palindrome.

// Note: in examples below and tests preview linked lists are presented as arrays just for simplicity of visualization: in real data you will be given a head node l of the linked list

// Example

//     For l = [0, 1, 0], the output should be
//     isListPalindrome(l) = true;

//     For l = [1, 2, 2, 3], the output should be
//     isListPalindrome(l) = false.


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


int eleAtIndex(ListNode<int> *head, int i){
    int it = 0;
    while(it<i){
        head = head ->next;
        it++;
    }
    return head->value;
}

int getLLLength(ListNode<int> *l){
    int listLen = 0;
    while(l!=NULL){
        listLen++;
        l=l->next;
    }
    return listLen;
}

ListNode<int>* getReverseofLL(ListNode<int> *l){
    ListNode<int> *prev = NULL;//NULL
    ListNode<int> *curr = l;//A
    ListNode<int> *temp = NULL;//A
    ListNode<int> *nextpt = l->next;//B
    // A->B->C->D->NULL
    while (nextpt != NULL) {
        curr->next = prev;
        temp = nextpt-> next;// 3
		nextpt->next = curr;
        
        prev = curr; 
        curr = nextpt;
        nextpt =temp;
    }
    return curr;
}

void traverse(ListNode<int> *l){
    while(l!=NULL){
        cout<<l->value<<"->";
        l = l->next;
    }
    cout<<"NULL"<<endl;
}

bool areLLSame(ListNode<int> *a, ListNode<int> *b){
    while(a!=NULL && b!=NULL){
        if(a->value!=b->value){
            return false;
        }
        a = a->next;
        b = b-> next;
    }
    return true;
}

bool isListPalindrome(ListNode<int> * l) {
    
    // APPROACH 1
    // int listLen = 0;
    // ListNode<int> *head = l;
    // while(l!=NULL){
    //     listLen++;
    //     l=l->next;
    // }
    // for(int i=0;i<listLen/2;i++){
    //     if(eleAtIndex(head, i) != eleAtIndex(head, listLen-i-1)){
    //         return false;
    //     }
    // }
    // return true;
    
    // APPROACH 1(OPTIMAL)
    ListNode<int> *h1 = l;
    int listLen = getLLLength(l);
    if(listLen == 0){
        return true;
    }
    for(int i=0;i<listLen/2;i++){
        l = l->next;
    }
    
    ListNode<int> *h2 = getReverseofLL(l);
    // traverse(h2);
    int length1 = getLLLength(h1);
    int length2 = getLLLength(h2);
    if(abs(length1-length2)>1){
        return false;
    }
    
    return areLLSame(h1,h2);
}

