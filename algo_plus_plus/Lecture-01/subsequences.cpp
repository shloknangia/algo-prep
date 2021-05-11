#include<bits/stdc++.h>
using namespace std;

void subsequences(char input[],char output[],vector<string> &vs,int i=0,int j=0){
    ///Base Case
    if(input[i]=='\0'){
        output[j]='\0';
//        cout<<output<<endl;
        string s(output);
        vs.push_back(s);
        return;
    }
    ///Rec Case
    ///Include the ith Character
    output[j] = input[i];
    subsequences(input,output,vs,i+1,j+1);

    ///Exclude the ith Character
    subsequences(input,output,vs ,i+1,j);

}


int main(){
    char input[] = "abcde";
    char output[10];
    vector<string> vs;
    subsequences(input,output,vs);
    ///SOrted Output
    sort(vs.begin(),vs.end());

    for(int i=0;i<vs.size();i++){
        cout<<vs[i]<<endl;
    }

	cout<<vs.size();



return 0;
}
