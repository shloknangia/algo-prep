#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define hashmap unordered_map<char, node*>
// each node can contain an many chars as next
// so we take a mini map to store next chars and their location

class node{
public:
    char data;
    hashmap h;
    bool isTerminal;

    node(char d){
        data = d;
        isTerminal = false;
    }
};


class trie{
    // we do need a root node wit null data at the start
    node* root;
public:
    trie(){
        root = new node('\0');
    }

    // need to functions - (to insert value) and (to find value)

    // Insertion
    void addWord(char* word){
        node* temp = root;
        // iterate over word to check if it exists
        for(int i=0; word[i]!='\0';i++){ //O(word length)
            char ch = word[i];
            if(temp->h.count(ch) == 0){ // check if ch exists in hashmap of root(or temp)
                // does not exists
                // so add a new node for ch
                node* child = new node(ch);
                temp->h[ch] = child;
                temp = child; // and come to that(new node)
            }
            else{
                // if already exists go to that node
                temp = temp->h[ch];
            }
        }
        // mark the last node as termonal
        temp->isTerminal = true;
    }

    // Lookup
    bool search(char* word){
        // similar to add
        node* temp = root;
        for(int i=0; word[i]!='\0';i++){
            char ch = word[i];
            if(temp->h.count(ch) == 0){
                // if not exists just retuen false;
                return false;
            }
            else{
                temp = temp->h[ch];
            }
        }
        // if(temp->isTerminal){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return temp->isTerminal;
    }


};

int main(){

    // Trie
    // tree like data structure
    // used for retrival of information
    // also called prefix tree
    // mostly string keys

    // can use linear search to find word form a list
    // for m words and length n it will take O(M*N)
    // can also use BST == O(log N) for balanced and O(H) for unbalanced
    // Trie - O(N) where N is length of word to be searched
    // but it uses space and some pre computation(i.e. building a trie of words)
    // so more space but time of query is less

    /* words: no, not, apple, ape
                                -
                               / \
                              a   n
                             /     \
                            p       o(t)
                           / \       \
                          p   e(t)    t(t)
                         /
                        l
                       /      
                      e(t)
        t -> terminal node
    */

   // info with each node
   // data - char
   // point to next node - hashmap(key, node*)
   // is terminal --- bool

   trie t;
   char word[][100] = {"apple","ape","not","mango", "no"};
   for(int i=0;i<5;i++){
      t.addWord(word[i]);
   }
   char search[100] = "no";
//    cin.getline(search,100);

   if(t.search(search)){
       cout<<"exists";
   }
   else{
       cout<<"not exists";
   }

    return 0;
};