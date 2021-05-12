#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}

int main()
{	

    // Sanjay's job- hacker blocks
    // Input: 
    // interger x
    // integer N- no. of employees
    // N lines contain names and salary
    // Output:
    // sort in dec order of salary then in in name(if sal same)and sal >x

    /*
        Input: 
            79
            4
            Eve 78
            Bob 99
            Suzy 86
            Alice 86
        Output:
            Bob 99
            Alice 86
            Suzy 86
    */

   int x, n;
   cin>>x;
   cin>>n;
   pair<string, int> emp[100];
   for(int i=0;i<n;i++){
       string name;
       int sal;
       cin>>name>>sal;
       emp[i].first = name;
       emp[i].second = sal;
   }

   sort(emp,emp+n, comparator);
   for(int i=0;i<n;i++){
       if(emp[i].second>x){
        cout<<emp[i].first<<" "<<emp[i].second<<endl;
       }
   }

	return 0;
}


