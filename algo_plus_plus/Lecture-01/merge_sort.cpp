#include<iostream>
using namespace std;

void merge(int a[],int x[],int y[],int s,int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    int k = s;

    while(i<=mid && j<=e){
        if(x[i]<y[j]){
            a[k++] = x[i++];
        }
        else{
            a[k++] = y[j++];
        }
    }

    while(i<=mid){
        a[k++] = x[i++];
    }
    while(j<=e){
        a[k++] = y[j++];
    }
    return;
}

void mergeSort(int a[],int s,int e){
    ///Base Case
    if(s>=e){
        return;
    }
    ///Rec Case
    /// Divide into two parts
    int x[100],y[100];

    int mid  = (s+e)/2;

    for(int i=0;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    /// Sort them recursively
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);

    ///Merge the sorted arrays
    merge(a,x,y,s,e);
}


int main(){
    int a[] = {5,7,6,8,3,1};
    int n = sizeof(a)/sizeof(int);

    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


return 0;
}
