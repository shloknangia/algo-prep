#include<iostream>
#include "stack.h"
#include "stack.h"
#include "Vector.h"
#include<cstring>
using namespace std;

class Book{
public:
    int price;
    char name[20];

    Book(){
    }

    Book(int p,char *n){
        price = p;
        strcpy(name,n);
    }
    void  print(){
        cout<<price<<endl;
        cout<<name<<endl;
    }

};

ostream& operator<<(ostream&os, Book&b){
    b.print();
    return os;
}

int main(){

    Stack<int> s;
    for(int i=1;i<=5;i++){
            s.push(i*i);
    }

    while(!s.isEmpty()){
            cout<< s.top()<<endl;
            s.pop();
    }

    Stack<Book> sb;

    Book b1(100,"C++");
    Book b2(200,"Java");
    Book b3(300,"Python");

    sb.push(b1);
    sb.push(b2);
    sb.push(b3);

    while(!sb.isEmpty()){
            Book topBook = sb.top();
            cout<<topBook;
            sb.pop();

    }



}
