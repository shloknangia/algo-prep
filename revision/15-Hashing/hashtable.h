#include<cstring>
using namespace std;

// #ifndef HASHTABLE_H
// #define HASHTABLE_H

// hashtable

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

// rehashing-> when table is nearly full we need to expand the table
// for that we need load factor = (current size/ total size)
// lets say LF = 0.7, then resize when table is 70% filled
// rehashinh is expensive, takes O(N) time

template<typename T>
class node{
    // to support collision and separate chaining we make linked list
    // need 3 things -> key , value and next
    // and every slot of hashtable will contain head of next so it will be node*
    // pointer to these slots will be of node**
    public:
        string key;
        T value;
        node<T>* next; // for templated class we need node<T> instead of node

        node(string k, T v){
            key = k;
            value = v;
        }

        // destructor
        // recursive dest call
        // it will first delete next then it self(if not null)
        ~node(){
            if(next!=NULL){
                delete next;
            }
        }

};

template<typename T>
class Hashtable{
    int cs;// Current Size
    int ts; // Max Arr size
    // pointer to slots will be of node**
    node<T>** buckets; 


    // h(s) = { sum(0->L-1) S[L-i-1] * 37^i }  mod tableSize
    // eg: key = bat
    // (b*37^2 + a*37^1 + t*37^0 ) mod table size
    int hashFn(string key){
        int L = key.length();
        int ans = 0;
        int p = 1; // as 37^0 = 1

        for(int i=0;i<L;i++){
            ans += key[L-i-1]*p;
            p *= 37;
            p %= ts; // so that it does not becomes very big (overflow)

            ans %= ts;
        }

        return ans;
    }

    void rehash(){
        // store old buckets
        node<T>** oldbuckets = buckets;
        int oldTs = ts;
        // update with new size
        ts = ts*2;
        cs = 0;
        buckets = new node<T>*[ts];
        // make app addresses 0 or point to null
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }

        // read from old table and add to new table
        // reading is similar to print 
        for(int i=0;i<oldTs;i++){
            node<T>* temp = oldbuckets[i];
            while(temp!=NULL){
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            // now row is copied, delete old table row
            delete oldbuckets[i];
        }

        // now need to delete whole array of slots  as well
        delete [] oldbuckets;
    }

public:
    Hashtable(int ds=7){ // default size
        cs = 0;
        ts = ds;
        buckets = new node<T>*[ts]; // array of pointers to store linked list
        // make app addresses 0 or point to null
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }
    }

    void insert(string key, T value){
        // for key we need hash-index
        int i = hashFn(key);

        node<T>* n = new node<T>(key, value);
        n-> next = buckets[i]; // whatever is in slot(null or any entry) is moved to next of new node
        buckets[i] = n;// new node is added to head of linked list
        // done

        // for rehashing(if needed)
        cs++;
        float load_factor = (float)cs/ts;
        if(load_factor>0.7){
            cout<<"load factor is: "<<load_factor<<endl;
            rehash();
        }
    }

    // print
    void print(){
        // iterate over buckets array
        for(int i=0;i<ts;i++){
            // print LL for each bucket
            node<T>* temp = buckets[i];
            cout<<"Bucket: "<<i<<"->";
            while(temp != NULL){
                cout<<temp->key<<", ";
                //<<temp->value<<endl; // cannot print value because it can be any object which would not work
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T* search(string key){
        int i = hashFn(key);
        if(buckets[i] != NULL){
            node<T>* temp = buckets[i];
            while(temp!=NULL){
                if(temp->key == key){
                    // return temp->value;
                    // as we moved return type as T->T* now need to return address
                    return &(temp-> value);
                }
                temp = temp->next;
            }
        }
        // if not found return NULL as we cannot return -1 for any object
        // to make it generic we return NULL
        // and then we will have to make return type as T -> T*
        return NULL;
    }

    node<T>* findAndDeleteNode(node<T>* head, string k) {
        if (head == NULL) return NULL;

        // if key found in current node
        if (head->key == k) {
            node<T>* ahead = head->next;
            cs--;
            delete head;    //VERY IMPORTANT STEP
            return ahead; // return next node
        }

        // check in next node
        head->next = findAndDeleteNode(head->next, k);
        return head;
    }


    void erase(string k){
        int i = hashFn(k);
        node<T>* head = buckets[i];// start of bucket where value may be

        buckets[i] = findAndDeleteNode(head, k);
    }

    // operator overloading
    // m['peach'] = 155;
    // we need to pass reference back to store new value so T&
    T& operator[](string key){
        T* temp = search(key); // try to find

        if(temp == NULL){ /// if not found insert
            T garbage; // create a box(empty)
            insert(key, garbage); // insert it ot location

            T* value = search(key); // as just inserted we will find it
            return *value; // return that box by reference
            // now value 155 will be stored at box
        }

        //else retuen the box found (update or search)
        return *temp;
    }


};

// #endif