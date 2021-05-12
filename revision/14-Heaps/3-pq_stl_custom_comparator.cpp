#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car{
    int x;
    int y;
    int id;
    public:

    Car(int id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist(){
        return x*x + y*y;
    }

    void print(){
        cout<<id<<" "<<x<<" "<<y<<endl;
    }

};

// to compare 2 cars
// Functor - Functional objects
class CarCompare{
    public:
        // method to overload () operator
        bool operator() (Car a, Car b){
            // return a.dist() < b.dist(); // for max heap
            return a.dist() > b.dist(); // for min heap
            // cout<<"Hello in car compare !";
        }
};

int main(){

    // Heaps or priority queue - STL 
    // custom comparator or functor(functional Object)(functions behaving as objects)
    // asked in interview
    // eg: in cartesian plane all points are (x,y), we need to find nearst 3 points to a point
    // can be done via sort but will take (N logN) time
    // using heap takes (N(for adding) + K logN)


    // for min heap
    priority_queue<Car, vector<Car>, CarCompare >  pq; 

    int x[10] = {5,6,17,18,9,11,0,3};
    int y[10] = {1,-2,8,9,10,91,1,2};

    for(int i =0;i<8;i++){
        Car c(i, x[i], y[i]);
        pq.push(c);
    }

    while(!pq.empty()){
        Car p = pq.top();
        p.print();
        pq.pop();
    }

    return 0;
}