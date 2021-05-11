#include<cstring>


class hashTable;

template<typename T>
class node{

	string key;
	T value;
	node* next;
	int hashfxn(string key){
		int L = key.length();
	}
public:	
	node(string k,T v){
		key = k;
		value = v;
		next = NULL;
	}
	
	friend class hashTable;
	
	
};

template<typename T>
class hashTable{
	node** buckets;
	int cs;
	int ts;//table size
public:
	hashTable(int ds = 7){
		cs =0;
		ts = ds;
		buckets =  new node*[ts];
		for(int i=0;i<ts;i++){
			buckets[i] = NULL;
		}
		
	}
	void insert(string key,T value){
		
	}
};
