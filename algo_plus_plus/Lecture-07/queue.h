#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue{
    int f,r;
    int ms;
    int cs;

    T *arr;
public:
    Queue(int s=5){
        f = 0;
        ms = s;
        r = ms-1;
        cs = 0;
        arr = new T[ms];
    }

    void push(T data){
        if(cs<ms){
            r =  (r + 1)%ms;
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
    bool isEmpty(){
        return cs==0;
    }
    bool isFull() const{
        return cs==ms;
    }
    int size() const{
        return cs;
    }
    ~Queue(){
        if(arr!=NULL){
            delete [] arr;
        }
    }

};
#endif // QUEUE_H
