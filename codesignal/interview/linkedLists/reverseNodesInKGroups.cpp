// Note: Your solution should have O(n) time complexity, where n is the number of elements in l, and O(1) additional space complexity, since this is what you would be asked to accomplish in an interview.

// Given a linked list l, reverse its nodes k at a time and return the modified list. k is a positive integer that is less than or equal to the length of l. If the number of nodes in the linked list is not a multiple of k, then the nodes that are left out at the end should remain as-is.

// You may not alter the values in the nodes - only the nodes themselves can be changed.

// Example

//     For l = [1, 2, 3, 4, 5] and k = 2, the output should be
//     reverseNodesInKGroups(l, k) = [2, 1, 4, 3, 5];
//     For l = [1, 2, 3, 4, 5] and k = 1, the output should be
//     reverseNodesInKGroups(l, k) = [1, 2, 3, 4, 5];
//     For l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] and k = 3, the output should be
//     reverseNodesInKGroups(l, k) = [3, 2, 1, 6, 5, 4, 9, 8, 7, 10, 11].

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

int lenthofLL(ListNode<int> *l){
    int i = 0;
    while(l!=NULL){
        i++;
        l = l->next;
    }
    return i;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    ListNode<int> *head = l;
        ListNode<int> *curr = head;
        ListNode<int> *temp = NULL;
        ListNode<int> *prev = NULL;
        ListNode<int> *nextpt = curr->next;
        int count = 0;
        // while(count<k && curr !=NULL){
        //     curr->next = prev;
        //     temp = nextpt->next;
        //     nextpt->next = curr;
            
        //     prev = curr;
        //     curr = nextpt;
        //     nextpt = temp;
        //     count++;
        // }
        if(lenthofLL(l)<k){
            return head;
        }
        while (curr != NULL && count < k)  
        {  
            nextpt = curr->next;  
            curr->next = prev;  
            prev = curr;  
            curr = nextpt;  
            count++;  
        }  
    if (nextpt != NULL){
        head->next = reverseNodesInKGroups(nextpt, k);
    }
    return prev;
}
