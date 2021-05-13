#include <iostream>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    // Hashmap
    // allows insertion of key-value pair
    // search(key)
    // delete (key)
    // hashmap<key, value>
    // header: <unordered_map>

    // 2 types available in C++
    // 1-> unordered_map(no fixed position for data to be inserted, so ordering may change, automatically), uses separate chaining with hash function
    // Complexity (Average Case i.e. 99% time): Insertion: O(1), Search: O(1), Deletion: O(1), exept for when rehashing occurs

    // 2-> map(fixed position as BST is used so it will self balance), used balanced BST or Red black tree( use if want to keep thing in sorted order)
    // Complexity (Average Case i.e. 99% time): Insertion: O(logN), Search: O(logN), Deletion: O(logN), exept for when rehashing occurs

    // hash function -> converts the key(lets say string) to integer(address to store in memory)
    // collision: if 2 strings hashed to same interger



    // 3 main factors while creating hashmap/hashtable
    // *hash function: key-> hash table index
    //      eg: if key is int
    //      key mod tablesize(take generally prime)
    //      eg: if key is string
    //      (Add up char's ASCII values 0-255) mod tablesize(take generally prime)
    //      "abcd" = 97+98+99+100 = 394 %tableSize (can lead to collision with anagrams)
    //   OR can use base 27 hash (or any base)
    //      bat = b*27^0 + a*27^1 + t*27^2 = int % table size
    //      
    // *table size- fixed size set at beginning
    // *collision handling scheme: cannot be avoided but can reduce chances by taking good hash function, 
    //      1. should distribute keys over table
    //      2. should be fast
    // Handle Collision:
    // 1. separate chaining(adding link to second value if already present i.e. linked list for every bucket) -- STL uses it

    unordered_map<string, int> m;

    // Insert
    m["mango"] = 100;

    // Second Insert
    m.insert(make_pair("Apple", 120));

    // Search
    // m.count(key) returns 1 or 0 if the element(or key) is present or not resp
    if(m.count("Apple") == 1){
        cout<<"price of Apple is: "<< m["Apple"]<<endl;
    }

    if(m.count("guava") == 0){
        cout<<"guava not found";
    }

    // Iterators
    auto f = m.find("mango");
    if(f != m.end()){
        // if not end -> key found
        cout<<"found:\n";
        cout<<f->first<<" "<<f->second<<endl;
        // first is "mango", second is 100
    }

    // delete
    m.erase("mango");
    if(m.count("mango") == 0){
        cout<<"mango not found";
        // mango deleted so not found
    }

    // iterate over all
    for(auto node:m){ // here auto = pair<string,int>
        cout<<node.first<<" "<<node.second<<endl;
    }

    // bucket iterate
    for(int i=0;i<m.bucket_count();i++){
        // iterate over every linked list
        cout<<"Bucket: "<<i<<"->";
        for(auto it = m.begin(i); it!=m.end(i);it++){
            // it is pointer to pair
            cout<<it->first<<", "<<it->second<<"||";
        }
        cout<<endl;
    }

    /*
        Output:
        Bucket: 0->
        Bucket: 1->
        Bucket: 2->
        Bucket: 3->
        Bucket: 4->
        Bucket: 5->
        Bucket: 6->Apple, 120||
        Bucket: 7->
        Bucket: 8->
        Bucket: 9->
        Bucket: 10->
    
    */

    return 0;
};