#ifndef STACK_H
#define STACK_H
#include "Vector.h"

template<typename T>
class Stack{

    Vector<T> v;

public:
    void push(T data){
        v.push_back(data);
    }
    void pop(){
        v.pop_back();
    }
    T top() const{
        return v[v.size()-1];
    }
    bool isEmpty() const{
        return v.size()==0;
    }
    int size() const{
        return v.size();
    }
};


#endif // STACK_H
