#include <iostream>
#include<bits/stdc++.h>
using namespace std;


    // 1007. Minimum Domino Rotations For Equal Row
    // Medium

    // In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

    // We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

    // Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

    // If it cannot be done, return -1.

    

    // Example 1:

    // Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
    // Output: 2
    // Explanation: 
    // The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
    // If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

    // Example 2:

    // Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
    // Output: -1
    // Explanation: 
    // In this case, it is not possible to rotate the dominoes to make one row of values equal.



class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n = tops.size();
        
        // top no should be common
        int noToCheck = tops[0];
        int tcount = 0;
        int tcount1 = 0;
        bool tnoNotFound = false;
        for(int i=1;i<n;i++){
            if(noToCheck == tops[i]) continue;
            else if(noToCheck == bottoms[i]){
                tcount1++;
            }
            else{
                tnoNotFound = true;
                break;
            }
        }
        tcount = tcount1;
        cout<<"tcount: "<<tcount<<endl;
        
        if(!tnoNotFound){
            int noToCheck = tops[0];
            int tcount2 = 1;
            bool tnoNotFound = false;
            for(int i=1;i<n;i++){
                if(noToCheck == bottoms[i]) continue;
                else if(noToCheck == tops[i]){
                    tcount2++;
                }
                else{
                    tnoNotFound = true;
                    break;
                }
            }
            tcount = min(tcount1, tcount2);
        }
        // cout<<"tcount: "<<tcount<<endl;
        
        
        // bottom no should be common
        noToCheck = bottoms[0];
        int bcount = 0;
        int bcount1 = 0;
        bool bnoNotFound = false;
        for(int i=1;i<n;i++){
            if(noToCheck == bottoms[i]) continue;
            else if(noToCheck == tops[i]){
                bcount1++;
            }
            else{
                bnoNotFound = true;
                break;
            }
        }
        bcount = bcount1;
        cout<<"bcount: "<<bcount<<endl;
        
        if(!bnoNotFound){
            int noToCheck = bottoms[0];
            int bcount2 = 1;
            bool bnoNotFound = false;
            for(int i=1;i<n;i++){
                if(noToCheck == tops[i]) continue;
                else if(noToCheck == bottoms[i]){
                    bcount2++;
                }
                else{
                    bnoNotFound = true;
                    break;
                }
            }
            bcount = min(bcount1, bcount2);
        }
        
        // cout<<"bcount: "<<bcount<<endl;
        
        // cout<<tnoNotFound<<" "<<tcount<<" "<<bnoNotFound<<" "<<bcount<<endl;
        
        if(tnoNotFound && bnoNotFound){
            return -1;
        }else if(!tnoNotFound && bnoNotFound){
            return tcount;
        }
        else if(tnoNotFound && !bnoNotFound){
            return bcount;
        }
        else
        return min(tcount, bcount);
        
        
    }
    
    
    // For reference
    //     int minDominoRotations(vector<int>& A, vector<int>& B) {
    //     vector<int> countA(7), countB(7), same(7);
    //     int n = A.size();
    //     for (int i = 0; i < n; ++i) {
    //         countA[A[i]]++;
    //         countB[B[i]]++;
    //         if (A[i] == B[i])
    //             same[A[i]]++;
    //     }
    //     for (int i  = 1; i < 7; ++i)
    //         if (countA[i] + countB[i] - same[i] == n)
    //             return n - max(countA[i], countB[i]);
    //     return -1;
    // }
    
    
};


int main(){


    return 0;
};