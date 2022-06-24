#include <iostream>
#include<bits/stdc++.h>
using namespace std;




// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:

// Input: nums = []
// Output: []

// Example 3:

// Input: nums = [0]
// Output: []



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
//         vector<vector<int>> result;
//         set<vector<int>> s;
//         sort(nums.begin(), nums.end());
        
//         if(nums.size() < 3){
//             return result;
//         }
        
//         for(int i=0;i<nums.size()-2;i++){
//             // vector<int> a =  
//             pair<vector<pair<int, int>>,int> p = findnumsWithSum(nums, nums[i]*-1, i);
//             cout<<p.first.size()<<" "<< nums[i];
//             if(p.second){
//                 for(auto k=0;k<p.first.size();k++){
//                     s.insert({nums[i], p.first[k].first, p.first[k].second});    
//                 }
                
//             }
//         }
        
//         for(auto j:s){
//             result.push_back(j);
//         }
        
//         return result;
        
        // O(N*log(N) + N(N-1))
        
        vector<vector<int>> result;
        int n = nums.size();
        
        // sort for easier finding
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            if(nums[i] > 0) break; 
            // all numbers from now on will be greater than 0, no point in continuing
            
            // if number is already seen, as sorted so same no will be together
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int s = i+1, e = n-1;
            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum<0){
                    s++;
                }
                else if(sum>0){
                    e--;
                }
                
                else{  // i.e. sum == 0
                    result.push_back({nums[i] , nums[s], nums[e]});
                    
                    // check if same no is next
                    int last_s = nums[s], last_e = nums[e];
                    while(s<e && last_s == nums[s]) s++;
                    while(s<e && last_e == nums[e]) e--;
                    
                }
            }
            
        }
        return result;
    }
    

    
    pair<vector<pair<int, int>>,int> findnumsWithSum(vector<int> nums, int x, int pos){
        int i =pos+1, j = nums.size()-1;
        vector<pair<int, int>> found;
        int value_found = 0;
        while(i<j){
            if((nums[i] + nums[j] == x) && i!=pos && j!=pos){
                value_found = 1;
                found.push_back(make_pair(nums[i],nums[j]));
                i++; j--;
            }
            else if (nums[i] + nums[j] < x){
                i++;
            }
            else{
                j--;
            }
        }
        return make_pair(found,value_found);
    }
};

int main(){


    return 0;
};