#include<vector>
using namespace std;

class Heap{
	
	bool minheap;
	vector<int> v;
	
	bool compare(int a,int b){
		if(minheap){
			return a<b;
		}
		else{
			return a>b;
		}
	}
	
	void heapify(int i){
		int minIndex = i;
		int left = i<<1;
		int right = left+1;
		
		int lastindex = v.size()-1;
		if(left<=lastindex && compare(v[left],v[minIndex])){
			minIndex = left;
		}
		if(right<=lastindex && compare(v[right],v[minIndex])){
			minIndex = right;
		}
		
		if(minIndex!=i){
			swap(v[i],v[minIndex]);
			heapify(minIndex);
		}
	}
public:	
	Heap(bool minH = true){
		minheap = minH;
		v.push_back(-1);
	}
	
	void push(int d){
		v.push_back(d);
		int index = v.size()-1;
		
		while(index>1 && compare(v[index])){
			
			swap(v[index],v[index/2]);
			index = index/2;
		}
	}
	int gettop(){
		if(v.size()>1){
			return v[1];
		}
	}
	
	void pop(){
		int index = v.size()-1;
		swap(v[1],v[index]);
		v.pop_back();
		heapify(i);
	}
	
	int size(){
		return v.size()-1;
	}
	
	bool isEmpty(){
		return v.size-1;
	}
	
};
