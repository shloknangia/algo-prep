#ifndef VECTOR_H
#define VECTOR_H
//taaki multiple declaration na ho

template<typename T>
class vector{

	T *arr;
	int cs;
	//current size
	int ms;
public:
	vector(int default_size = 4){
		arr = new int[default_size];
		cs = 0;
		ms = default_size;
	}		
	
	void push_back(const T d){//does not change d
		if(cs == ms){
			//expand the vector if full
			T *old = arr;
			T oldsize = ms;
			ms = ms<<1;
			arr = new T[ms];
			
			for(int i=0;i<cs;i++){
				arr[i] = old[i];
			}
			
			delete[] old;
//			old = NULL;			
		}
		arr[cs] = d;
		cs++;
	}
	
	void pop_back(){
		if(cs>0){
			cs--;
		}
	}
	int size() const{
		return cs;
	}
	int capacity() const{	//does not change any private member for class
		return ms;
	}
	
	T operator[] (int i) const{	//const fxn can only call const fxn
		return arr[i];
	}
};
#endif
