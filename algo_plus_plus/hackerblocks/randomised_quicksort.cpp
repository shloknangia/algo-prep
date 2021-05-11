#include<iostream>
#include<algorithm>
using namespace std;


int findpivot(int a[],int s,int e){
    
    int pivot = a[e];
    int p = s;
    for(int i=s;i<e;i++){
        if(a[i]<=pivot){
            swap(a[i],a[p]);
            p++;
        }
    }
    
    swap(a[p],a[e]);
    
    return p;
}

int randomised_findpivot(int a[],int s,int e){
    
    int pivot = rand() % (e-s+1) + s;
    swap(a[pivot],a[e]);
    int pp = findpivot(a,s,e);
//    cout<<pp<<endl;
    return pp;
}

void quick_sort(int a[],int s,int e){
    
    if(s<=e){
        int pivot = randomised_findpivot(a,s,e);
//         cout<<pivot<<endl;
        quick_sort(a,s,pivot-1);
        quick_sort(a,pivot+1,e);
    }
    return;
    
}

int main() {

    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

	return 0;
}
