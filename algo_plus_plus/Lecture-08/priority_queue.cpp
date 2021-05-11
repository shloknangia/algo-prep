#include<iostream>
#include<queue>
#include<functional>
#include<cstring>
using namespace std;

class Person{
public:
    char name[100];
    int money;

public:
    Person(){
    }
    Person(char *n,int m){
        strcpy(name,n);
        money = m;
    }

};

class PersonCompare{
public:
    bool operator()(){
        cout<<"Hey !";
    }
    bool operator()(const Person &p1,const Person &p2){
        return p1.money>p2.money;
    }

};

int main(){

    priority_queue<int,vector<int>, greater<int> > p; /// Min Heap
    priority_queue<int> pq;  ///Max Heap

    int a[] = {7,6,5,4,3,1,2,9,10,15};
    for(int i=0;i<10;i++){
        pq.push(a[i]);
    }

    while(!pq.empty()){
        cout<< pq.top()<<" ";
        pq.pop();
    }

    priority_queue<Person,vector<Person>,PersonCompare> pp;

    Person p1("Prateek",100);
    Person p2("Nimit",150);
    Person p3("Piyush",2);

    pp.push(p1);
    pp.push(p2);
    pp.push(p3);

    PersonCompare t,t2;

    t2();
    cout<<"Answer is ";
    bool ans = t(p1,p2);
    cout<<ans<<endl;

    while(!pp.empty()){
        Person tp = pp.top();
        cout<<tp.name<<" "<<tp.money<<endl;
        pp.pop();

    }






return 0;
}
