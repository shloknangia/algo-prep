//Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such elements, return -1




// For a = [2, 1, 3, 5, 3, 2], the output should be firstDuplicate(a) = 3.

// There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

// For a = [2, 2], the output should be firstDuplicate(a) = 2;

// For a = [2, 4, 3, 5, 1], the output should be firstDuplicate(a) = -1.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int firstDuplicate(vector<int> a) {
    map<int, int> occ;
    for(int i=0;i<a.size();i++){
        auto fs = occ.find(a[i]);
        if(fs!=occ.end()){
            return a[i];
        }
        else{
            occ.insert(make_pair(a[i], 1));
        }
    }
    return -1;
}

main(){
    vector<int> a;
    cout<< firstDuplicate(a);
    return 0;
}
