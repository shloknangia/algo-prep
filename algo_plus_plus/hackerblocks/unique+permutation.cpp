    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    
    set<string> s;
    void permutation(char a[],int i){
        
        if(a[i] == '\0'){
            string ss(a);
            s.insert(ss);
            return;
        }
        
        for(int j = i;a[j]!='\0';j++){
            swap(a[i],a[j]);
            permutation(a,i+1);
            swap(a[i],a[j]);
        }
        
        
    }
    
    int main() {
    
        char a[10];    
        cin>>a;
        
        permutation(a,0);
        
        // sort(s.begin().s.end());
        for(set<string>::iterator it = s.begin();it!=s.end();it++){
            cout<<*it<<endl;
        }
    
    	return 0;
    	
    }
