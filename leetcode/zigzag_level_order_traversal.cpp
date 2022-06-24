#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:

    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:

// Input: root = [1]
// Output: [[1]]

// Example 3:

// Input: root = []
// Output: []


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(root == NULL){
            return result;
        }
        int dir = 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            
            int currentlevelSize = q.size();
            vector<int> currentLevelItems(currentlevelSize);
            
            for(int i=0;i<currentlevelSize;i++){
                
                TreeNode* temp = q.front();
                q.pop();    
                
                
                if(temp !=NULL) {
                    if(!dir){
                        currentLevelItems[i] = temp->val;
                    }else{
                        currentLevelItems[currentlevelSize -i -1] = temp->val;
                    }    
                }
                
                if(temp->left !=NULL) q.push(temp->left);
                if(temp->right !=NULL) q.push(temp->right);   
            }                
            
            result.push_back(currentLevelItems);
            dir = !dir;
            
        }
        return result;        
    }
    

};


int main(){


    return 0;
};