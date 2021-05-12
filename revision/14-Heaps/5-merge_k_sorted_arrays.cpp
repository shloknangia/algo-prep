#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef  tuple<int, int, int>  iii;

class Comparator {
public:
    bool operator()(const iii& t1, const iii& t2) {
        //if t1 should appear before t2
        return get<0>(t1) > get<0>(t2);
    }
};

vector<int> mergeKSorted(vvi& v, int k) {
    // iii t; //val, arrayNo, idxNo; val, r, c

    priority_queue<iii, vector<iii>, Comparator> minHeap;
    vector<int> ans;

    //setting the scene
    for (int i = 0; i < k; ++i) {
        minHeap.push(make_tuple(v[i][0], i, 0));
    }

    while (minHeap.empty() == false) {
        iii t = minHeap.top();
        minHeap.pop();
        ans.push_back(get<0>(t));

        //check for r, c+1
        int r = get<1>(t);
        int c = get<2>(t) + 1;
        if (c < v[r].size()) {
            //insert
            minHeap.push(make_tuple(v[r][c], r, c));
        }
    }
    return ans;
}

void input(vvi& v, int k) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> v[i][j];
        }
    }
}

void print(vi& v, int k) {
    for (int i = 0; i < v.size(); ++i) {
        // for (int j = 0; j < k; ++j) {
            cout << v[i] << " ";
        // }
        // cout << endl;
    }
}

int main(){

    // Merge K-sorted Arrays
    // assume k>2 as for 2 it will be simple merge
    /* eg:
        Input: for k=3
            0, 4, 10, 12,...
            1, 3, 5, 7,...
            2, 4, 12, 15, 20,...
        Output:
            0, 1, 2, 3, 4, 4, 5,...
    */
   // Brute force: add all into same array and sort it
   // complexity: K*N*log(K*N) [as total elements = K*N]
   // more efficient using min heap of size K

   // steps:
   // add first element of all k arrays
   // remove min
   // add next element of array whose element was removed
   // if one of the array is finished, add INT_MAX

    // Complexity: K*N*(log K)
    // total elements = KN
    // each insertion and poping takes (log K) time
    
    
    
    // priority_queue<int, vector<int> , greater<int> > pq;

    int k;
    cin >> k;
    // vector<int> v(2, 1);

    vector<vector<int> > v(k, vector<int>(k));
    input(v, k);

    vector<int> ans = mergeKSorted(v, k);

    print(ans, k);

    
    
    return 0;
}