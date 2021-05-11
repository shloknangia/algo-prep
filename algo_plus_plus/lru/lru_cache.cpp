#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class LRUcache{
	int capacity;
	// <key,<value,key iterator> >
	unordered_map<int,pair<int , list<int>::iterator>> cache;
	//list of keys, first = MRU, last = LRU
	list<int> lru;

public:
	
	LRUcache(int _capacity){
		capacity = _capacity;
	}
	
	int get(int key){
		
		auto item = cache.find(key);
		//if key doesnt exist return -1
		if(item == cache.end()){
			return -1;
		}
		//if key exist return the value and update LRU
		use(item);
		return item->second.first;
	}
	
	void set(int key,int value){
		auto item = cache.find(key);
		//if key exist ,just set the value and update
		if(item !=cache.end()){
			use(item);
			cache[key] = {value,lru.begin()};
			return;
		}
		//if key doesnt exist
		//check the capacity
		if(cache.size() == capacity){
			//pop out LRU item
			cache.erase(lru.back());
			lru.pop_back();
		}
		lru.push_front(key);
		//insert new key value pair
		cache.insert({key,{value,lru.begin()}});
		
		
		
		
	}
	
	void use(unordered_map<int,pair<int , list<int>::iterator>>::iterator& it){
		lru.erase(it->second.second);
		lru.push_front(it->first);
		it->second.second = lru.begin();
	}
};


int main(){
	LRUcache *cache = new LRUcache(2);
//	cache->set(1,1);
//	cache->set(2,2);
//	cout<<cache->get(1);//should be 1
//	cache->set(3,3);
//	cout<<cache->get(2);//should be -1

	cache->set(1,2);
	cout<<cache->get(1);
	
	
	cache->set(1,2);
	cache->set(2,2);
	cache->set(1,5);
	cache->set(4,5);
	cache->set(6,7);
	cout<<cache->get(4);
	cout<<cache->get(1);
	return 0;
}

/*
 1 : 1
 2 : 2

*/
