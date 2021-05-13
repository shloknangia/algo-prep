#include <iostream>
#include<bits/stdc++.h>
#include"hashtable.h"
using namespace std;

int main(){

    // (Fruit, 100) key= string, price = int
    Hashtable<int> h(8); // if we increase size off table , collisions will be reduced
    h.insert("Mango", 100);
    h.insert("Apple", 170);
    h.insert("Guava", 140);
    h.insert("Banana", 130);
    h.insert("Chiku", 120);

    h.print();
    /*
    Output: 
        Bucket: 0->Chiku, Guava,
        Bucket: 1->Banana,
        Bucket: 2->Apple, Mango,
        Bucket: 3->
        Bucket: 4->
        Bucket: 5->
        Bucket: 6->
        Bucket: 7->

    */


   // rehashing
   h.insert("Pineapple", 199);
   h.insert("Dragon Fruit", 110);
   h.print();

   /*
    Output:
        Bucket: 0->Guava,
        Bucket: 1->Dragon Fruit, Banana,
        Bucket: 2->Apple,
        Bucket: 3->
        Bucket: 4->
        Bucket: 5->
        Bucket: 6->
        Bucket: 7->
        Bucket: 8->Chiku,
        Bucket: 9->
        Bucket: 10->Mango,
        Bucket: 11->
        Bucket: 12->
        Bucket: 13->
        Bucket: 14->Pineapple,
        Bucket: 15->
    */


   h["Mango"] = 101; // update and get(search)
   h["peach"] = 155; // insert
   h.print();

   /*
    Output:
        Bucket: 0->Guava,
        Bucket: 1->peach, Dragon Fruit, Banana,
        Bucket: 2->Apple,
        Bucket: 3->
        Bucket: 4->
        Bucket: 5->
        Bucket: 6->
        Bucket: 7->
        Bucket: 8->Chiku,
        Bucket: 9->
        Bucket: 10->Mango,
        Bucket: 11->
        Bucket: 12->
        Bucket: 13->
        Bucket: 14->Pineapple,
        Bucket: 15->
        Mango
        101
   */

   // test search
   string f;
   getline(cin,f);
   int *price = h.search(f);
   if(price != NULL){
       cout<<*price;
   }
   else{
       cout<<"not found";
   }


    return 0;
};