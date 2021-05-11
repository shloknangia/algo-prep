// Note: Your solution should have O(l1.length + l2.length) time complexity, since this is what you will be asked to accomplish in an interview.

// Given two singly linked lists sorted in non-decreasing order, your task is to merge them. In other words, return a singly linked list, also sorted in non-decreasing order, that contains the elements from both original lists.

// Example

//     For l1 = [1, 2, 3] and l2 = [4, 5, 6], the output should be
//     mergeTwoLinkedLists(l1, l2) = [1, 2, 3, 4, 5, 6];
//     For l1 = [1, 1, 2, 4] and l2 = [0, 3, 5], the output should be
//     mergeTwoLinkedLists(l1, l2) = [0, 1, 1, 2, 3, 4, 5].

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
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    
    ListNode<int> *head = NULL;
    ListNode<int> *temphead = NULL;
    while(l1!=NULL && l2 !=NULL){
        ListNode<int> *temp = new ListNode<int>(0);
        if(l1->value <l2->value){
            temp->value = l1->value;
            if(temphead !=NULL){
                temphead ->next = temp;
                temphead = temp;
            }else{
                temphead = temp;
                head = temphead;
            }
            
            // temp->next = head;
            // head = temp;
            l1 = l1->next;
        }
        else{
            temp->value = l2->value;
            if(temphead !=NULL){
                temphead ->next = temp;
                temphead = temp;
            }else{
                temphead = temp;
                head = temphead;
            }
            // temp->next = head;
            // head = temp;
            l2 = l2->next;
        }
    }
    
    while (l1!=NULL){
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = l1->value;
        if(temphead !=NULL){
            temphead ->next = temp;
            temphead = temp;
        }else{
            temphead = temp;
            head = temphead;
        }
        // temp->next = head;
        // head = temp;
        l1 = l1->next;
    }
    
    while (l2!=NULL){
        ListNode<int> *temp = new ListNode<int>(0);
        temp->value = l2->value;
        if(temphead !=NULL){
            temphead ->next = temp;
            temphead = temp;
        }else{
            temphead = temp;
            head = temphead;
        }
        // temp->next = head;
        // head = temp;
        l2 = l2->next;
    }
    return head;

}
