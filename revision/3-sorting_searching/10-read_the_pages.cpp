#include<iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll books[], ll n, ll k, ll ans){
    // validate if it can be divided into k parts(student)

    int students = 1;
    ll current_pages = 0;

    for(int i=0;i<n;i++){
        if((current_pages + books[i])> ans){ // cannot read more pages
            current_pages = books[i]; // for new student, remove other book just ith book
            students++; // new student
            if(students > k){ // student more that k not needed, config fails
                return false;
            }
        }
        else{ // can read more pages
            current_pages += books[i];
        }
    }

    // if loop completes without breaking (students ==k)
    return true;

}

ll binarySearchOnBooks(ll books[], ll n, ll k){

    ll s = 0, e = 0;
    ll total_pages = 0;
    for(int i=0;i<n;i++){
        total_pages += books[i];
        s = max(s, books[i]);// as everyone will read min of 1 book, so ans is min that pages, alsi it will be last element as sorted
    }
    e = total_pages;
    ll finalAns = s;

    while(s<=e){

        ll mid = (s+e)/2;

        if(isValidConfig(books, n, k ,mid)){ // mid is current ans
            // if true search in left part
            // i.e. find min possible number
            e = mid -1;
            finalAns = mid; // as this is also true
        }
        else{
            // else search in right part
            s = mid +1;
        }
    }

    return finalAns;
}

int main(){

    // Read the Books (IMP)
    //You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized. You have to find the maximum number of pages, a student can have in this assignment of books.
    // Minimize max no. of pages each student reads

    /* eg:
        Input: 
            N: 4 (books)
            M: 2 (students)
            Pi: 10, 20 , 30 , 40
        Output:
            [10, 20, 30] [40]
            i.e. 60 and 40
    */

   // Brute force: try all the segments = (n-1)C(m-1) ~ exponential

   // constraint given: 1<=N<10^5, 1<=M<=N, 1<=Pi<=10^9 (so need long long)
   // so need to use  N*logN, cannot use N^2

   // Ans: modified Binary Search
   // find search space(pages), min = 0, max = sum of all Pi
   // apply binay search find mid
   // kepp mid as max, start dividing pages(sum upto max) in students 
   // if students == M, return true else false
   // if students >M , move right
   // if config found, move left as we need to minimize that number



    ll n;
    ll m;
    cin>>n>>m;
    ll books[10005];
    for(int i=0;i<n;i++){
        cin>>books[i];
    }

    cout<< binarySearchOnBooks(books, n, m)<<endl;

    return 0;

}