#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    // Hashing Questions - O(N) time

    // Find pair of elemenys which sum to 0
    // eg: 1 3 -1 6 2 7 -6
    // add in hashmap
    // now check if (0-no) exists in hashmap
    // like for 6, search if -6 exists

    // Union and Intersection of 2 linked lists
    // eg: [1 3 2 5 7] and [2 5 6 9 11]
    // Intersection:
    // add first arr in hashmap
    // now for every element in arr2 check if it is present in hashmap
    // if yes add it in ans array
    // Union:
    // add both lists in hashmap
    // as we know keys are always unique, so all elements will be stored once

    // Remove duplicates from array
    
    // Remove cycle from LL using Hashing
    // eg: 1 -> 2 -> 3 -> 4 -> 6
    //          |--------------v
    //add address of all elements in hashmap
    // if that address is encountered again -> cycle is present
    // call : findCycle(head)
    /* O(N) time, O(N) space
    but floyd cycle is better as it takes O(N) time, O(1) space

        bool findCycle(node* head){
            node* temp = head;
            // key is address of node*, bool is seen or not seen
            unordered_map<node*, bool> m;

            while(temp!=NULL){
                if(m[temp] == true){
                    cout<<"cycle found";
                    return true
                }
                m[temp] = true;
                temp = temp->next;
            }
        }
    */


   // print a binary tree in vertical order
   /* eg: value(distance), +1 in right, -1 in left
            1(0)
          /    \
        2(-1)   3(1)
       / \      / \
    4(-2) 5(0) 6(0) 7(2)
             \       \
             8(1)     9(3)
        Output: 4 2 1 5 6 3 8 7 9
    */
    // take dist as key and store vector as value in hashmap

    /*
    Call:
        map<int, vector<int> > m; // map has sorted kays
        vop(root);
        // as taken map now all keys already sorted just iterate
        for(auto it = m.begin();it!=m.end();it++){
            cout<<it->first<<"->";
            for(int i =0;i<it->second.size();i++){
                cout<<it->second[i]<<", ";
            }
            cout<<endl;
        }

    function:
        void vop(node* root, map<int, vector<int> > &m int d = 0){

            if(root == NULL){
                return;
            }

            m[d].push_back(root->data);
            vop(root->right, m, d+1);
            vop(root->left, m, d-1);

        }
    */

    return 0;
};