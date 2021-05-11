#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class queue{
	
	int f,r;
	int ms,cs;
public:
	T *arr;
	queue(int s=5){
		f=0;
		ms = s;
		r = ms-1;
		cs = 0;
		arr = new T[ms];
	}
	
	void push(T data){
		if(cs<ms){
			r= (r+1)%ms;
			arr[r] = data;
			cs++;
		}
		
	}
	
	void pop(){
		
		if(cs>0){
			f = (f+1)%ms;
			cs--;
		}
	}
	T front(){
		return arr[f];
	}
	
	bool isempty(){
		return cs==0;
	}
	bool isfull(){
		return cs == ms;
	}
	
	~queue(){
		if(arr!=NULL){
			delete[] arr;
			
		}
	}
};

#endif
