#include<iostream>
#include<set>
using namespace std;

set<string> ss;

void print(char input[],int i=0){
    ///Base Case
    if(input[i]=='\0'){
       // cout<<input<<endl;
        string s(input);
        ss.insert(s);
        return;
    }

    ///Rec Case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        print(input,i+1);
        ///Backtrack - Restore original array
        swap(input[i],input[j]);
    }

}

int main(){
    char input[10] = "aabc";
    print(input);

    for(set<string>::iterator it=ss.begin();it!=ss.end();it++){
        cout<<*it<<endl;
    }

    /*
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(1);

    for(auto it = s.begin();it!=s.end();it++){
        cout<< *it<<" ";
    }
    */



return 0;
}
