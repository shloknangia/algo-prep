/// Given a sorted and rotated array
/// Find out the Highest Element(Pivot) element in the array
/// Using Binary Search.
/// Eg a[] = {5,6,7,1,2,3,4}
#include<iostream>
using namespace std;


int main(){
    ///Modify the logic !
    int a[] = {5,5,5,5,6,3,4};
    int n = sizeof(a)/sizeof(int);
    int s =0;
    int e = n-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(mid<e && a[mid]>a[mid+1]){
            cout<<mid<<" ";
            break;
        }
        if(mid>s && a[mid]<a[mid-1]){
            cout<<mid-1<<" ";
            break;
        }
        if(a[s]>=a[mid]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    if(s>e){
        cout<<"Pivot element doesn't exist"<<endl;
    }


return 0;
}