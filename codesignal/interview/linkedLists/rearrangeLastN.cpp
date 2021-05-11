// Note: Try to solve this task in O(list size) time using O(1) additional space, since this is what you'll be asked during an interview.

// Given a singly linked list of integers l and a non-negative integer n, move the last n list nodes to the beginning of the linked list.

// Example

//     For l = [1, 2, 3, 4, 5] and n = 3, the output should be
//     rearrangeLastN(l, n) = [3, 4, 5, 1, 2];
//     For l = [1, 2, 3, 4, 5, 6, 7] and n = 1, the output should be
//     rearrangeLastN(l, n) = [7, 1, 2, 3, 4, 5, 6].



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

int getLLLength(ListNode<int> * l){
    int i = 0;
    while(l!=NULL){
        l = l->next;
        i++;
    }
    return i;
}

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    
    ListNode<int> *head = l;
    ListNode<int> *prev = NULL;
    
    // find break
    int len = getLLLength(l);
    if( n==0 || len == 0 || len==n){
        return head;
    }
    for(int i=0;i<len-n;i++){
        prev = l;
        l = l->next;
    }
    prev->next = NULL;
    ListNode<int> *newhead = l;
    
    //join
    while(l->next!=NULL){
        l = l->next;
    }
    l->next = head;

    return newhead;
}
