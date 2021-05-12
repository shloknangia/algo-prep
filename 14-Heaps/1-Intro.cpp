#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap{
        vector<int> v; // to store data
        bool minHeap; // by default make it min heap

        void heapify(int i){ // to correct the order of heap

            int left  = 2*i;
            int right = 2*i +1;

            // assume current element is minimum
            int minIndex = i;

            // if left exists and condition
            if(left < v.size() && compare(v[left],v[i]) ){
                minIndex = left;
            }

            // if right exists and condition
            if(right < v.size() && compare(v[right],v[minIndex]) ){
                minIndex = right;
            }
            
            // if min index is changed from i
            if(minIndex != i){
                swap(v[minIndex], v[i]); // change values
                heapify(minIndex); // heapify next level
            }

            

        }


    public:

        Heap(bool type = true){ // by default min heap is true
            minHeap = type;
            // block 0th index by adding -1
            v.push_back(-1);
        }

        // custom compare function to handle hin and max heap
        bool compare(int a, int b){
            if(minHeap){
                return a<b;
            }
            else{
                return a>b;
            }
        }

        void push(int data){ // to add data point
            // insert at last
            v.push_back(data);
            
            // to take that element to correct position to restore heap property
            int index = v.size()-1; // location of last index
            int parent = index/2;


            /*
                // For Min Heap foll this true
                // repeat till root node and meet condition
                while(index>1 && v[index] < v[parent]){
                    swap(v[index], v[parent]);
                    index = parent; // as swapped new element is at parent
                    parent = parent/2; // now move to new parent
                }

            */

           
            // repeat till root node and meet condition
            while( index>1 && compare(v[index], v[parent]) ){
                swap(v[index], v[parent]);
                index = parent; // as swapped new element is at parent
                parent = parent/2; // now move to new parent
            }

        }

        bool isEmpty(){
            return v.size() == 1;
        }

        int top(){
            return v[1]; // first position will contan min/max
        }

        void pop(){
            // Remove the top most element

            // swap first and last element
            int last = v.size()-1;
            swap(v[1], v[last]);

            // remove last element
            v.pop_back();

            // heapify root
            heapify(1);
        }


};


int main(){

    // Heaps or priority queue
    // elements are poped wrt their priority
    // Complexity
    // Find/Get: O(1), Insert: O(log N), Remove: O(log N)

    // Complete Binary Tree-- all levels are complete except for last(partially filled and left to right)
    // Heap Order Property -- min(node<= children) and max(node>= children) heap

    /* Min Heap
            1
          /   \
        2      3
       / \    / \
      17  19 36  7
     /  \
    25   100
    */


   // Implementation
   // can use Binary tree but for that insertion will take lavel order traversal(O(N) time)
   // as it is complete binary tree we can use array numbering

   /* Min Heap
            1(1)
          /    \
        2(2)    3(3)
       / \      /   \
   17(4) 19(5) 36(6)  7(7)
     /  \
  25(8) 100(9)

    Using array

    [x,1,2,3,17,19,36,7,25,100]

            i       // parent position
          /   \
         2i   2i+1  // children at these position
    */


   // Insertion -- O(log N)
   // added at end as new node
   // compare to parent at i/2 pos
   // if small(or large for max) swapped with parent node
   // repeat till reached at root node
   // or stor if condition not met


   // Deletion(or POP) in heaps - O(log N)
   // only min(or max) elements are removed
   // 1. swap first and last node
   // 2. pop last node
   // 3. Heapify(root node) - i.e. correct heap property if violated


    Heap h;

    h.push(5);
    cout<<h.top()<<endl;// 5
    h.push(15);
    cout<<h.top()<<endl;// 5
    h.push(2);
    cout<<h.top()<<endl;// 2
    h.push(20);
    cout<<h.top()<<endl;// 2
    h.push(3);
    cout<<h.top()<<endl;// 2

    cout<<"Deletion:"<<endl;
    while(!h.isEmpty()){
        cout<<h.top()<<endl;
        h.pop();
    }

    /*
        Output: 
            2
            3
            5
            15
            20
    */

    return 0;
}