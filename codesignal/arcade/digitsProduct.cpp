// Given an integer product, find the smallest positive (i.e. greater than 0) integer the product of whose digits is equal to product. If there is no such integer, return -1 instead.

// Example

//     For product = 12, the output should be
//     digitsProduct(product) = 26;
//     For product = 19, the output should be
//     digitsProduct(product) = -1.
#include<bits/stdc++.h>
using namespace std;

int digitsProduct(int product) {
    if(product == 1) return 1;
    if(product == 0) return 10;

    vector<int> f;
    for(int i=9;i>1;){
        if(product%i ==0){
            f.push_back(i);
            product /=i;
            cout<<i<<"\t"<<product<<endl;
            i = 9;
        }
        else{
            i--;
        }
    }
    if(product != 1){
        return -1;
    }
    sort(f.begin(),f.end());
    int sum =0;
    for(auto h:f){
        sum = sum*10 + h;
    }
    return sum;

}


// int digitsProduct(int product) {
//     if (product < 10)
//         return product ?: 10;
//     std::string r;
//     for (int i = 9; i > 1; i--) {
//         while (product % i == 0) {
//             product /= i;
//             r = char('0' + i) + r;
//         }
//     }
//     return product == 1 ? std::stoi(r) : -1;
// }

