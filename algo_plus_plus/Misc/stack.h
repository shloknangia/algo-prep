#ifndef STACK_H
#define STACK_H
#include "vector_class.h"

template<typename T>
class stack{
	
	vector<T> v;
	
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
	bool isempty() const{
		return v.size() == 0;
	}
	
	int size() const{
		return v.size();
	}
	
};
#endif
