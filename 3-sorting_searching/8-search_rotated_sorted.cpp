#include<iostream>
using namespace std;

// Find number in rotated sorted array
// 6 7 1 2 3 4 5
// find 7
// Using binary search

int searchIn(int a[], int s, int e,int key){
    //base case
    if(s>e){
        return -1;
    }
	// Rec case
    int mid = (s+e)/2;

    if(a[mid]==key){
        return mid;
    }

    // midpoint in left half (first line)
    if(a[s]<=a[mid]){
        if(key>= a[s] && key <=a[mid]){
            return searchIn(a, s, mid-1, key);
        }
        else{
            return searchIn(a, mid+1, e, key);
        }
    }

    // midpoint in right half (second line)
    if(key>= a[mid] && key <=a[e]){
        return searchIn(a, mid+1, e, key);
    }
    // else{
        return searchIn(a, s, mid-1, key);
    // }
    

	

}

int main(){
	int a[] = {6,7, 1,2,3,4,5};
    // int a[] = {5,6,7,1,2,3,4};
	cout<<searchIn(a, 0, 6, 4)<<endl;
    // returns 5

}