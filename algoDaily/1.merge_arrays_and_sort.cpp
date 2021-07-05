#include <iostream>
using namespace std;

// Given two sorted arrays X[] and Y[] of size m and n each where m >= n and X[] has exactly n vacant cells, merge elements of Y[] in their correct position in array X[], i.e., merge (X, Y) by keeping the sorted order.

int M = 9;
int N = 5;


void print(int x[]){
    for(int i=0;i<M;i++){
        cout<<x[i]<<", ";
    }
    cout<<endl;
}

void  merge(int x[], int y[]){
    int xp = 0, yp = 0, cp = 0;

    while(xp< M && yp<N){

        if(x[xp] == 0){
            xp++;
        }
        else{
            if(x[xp]>y[yp]){
                x[cp] = y[yp];
                yp++; cp++;
            }
            else{
                x[cp] = x[xp];
                xp++; cp++;
            }
        }
    
    }

    while(xp<M){
        x[cp] = x[xp];
        xp++; cp++;
    }

    while(yp<N){
        x[cp] = y[yp];
        yp++; cp++;
    }

    print(x);
}

int main() {
    int X[] = { 0, 2, 0, 3, 0, 5, 6, 0, 0};
    int Y[] = { 1, 8, 9, 10, 15 };
    // Output:
    // 1, 2, 3, 5, 6, 8, 9, 10, 15,
    merge(X, Y);
    return 0;
}
