#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// 19. Remove Nth Node From End of List
// Medium

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:

// Input: head = [1], n = 1
// Output: []

// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

 

// Constraints:

//     The number of nodes in the list is sz.
//     1 <= sz <= 30
//     0 <= Node.val <= 100
//     1 <= n <= sz

 

// Follow up: Could you do this in one pass?




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         int l  =0;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             temp = temp->next;
//             l++;
//         }
//         int nodeTodel = l-n;
//         // cout<<l<<" "<<nodeTodel<<endl;
//         int count = 1;
        
//         if(nodeTodel == 0){
//             head = head->next;
//             return head;
//         }
        
//         temp = head;
        
        
//         while(temp!=NULL){
//             // cout<<count<<endl;
//             if(count==nodeTodel){
//                 // cout<<"here "<<temp->val<<endl;
//                 temp->next= temp->next->next;
//                 break;
//             }
//             temp = temp->next;
//             count++;
//         }
//         return head;
        
        
        // one pass
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++) fast = fast->next;
        if(fast == NULL){
            head = head->next;
            return head;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast = fast->next;
        }
        slow->next =slow->next->next;
        return head;
        
        
    }
};
int main(){


    return 0;
};