#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
bool stringCompare(const string &s1,const string &s2){
    return s1.length()<s2.length();
}


int main(){

    int a[] = {1,5,4,3,2};
    sort(a,a+5,compare);

    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }

    string s;
    cin>>s;

    string s2(" World");
    cout<<s + s2 <<endl;

    ///Array of Strings
    string fruits[] = {"apple","az","ape","papaya"};
    vector<string> vs;

    for(int i=0;i<4;i++){
        vs.push_back(fruits[i]);
    }

    sort(vs.begin(),vs.end(),stringCompare);

    for(int i=0;i<vs.size();i++){
        cout<<vs[i]<<endl;
    }



return 0;
}
