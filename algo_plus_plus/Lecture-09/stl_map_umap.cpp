#include<iostream>
#include<unordered_map>
#include<cstring>
# define mp make_pair<string,Fruit>
#include<map>
using namespace std;

class Fruit{
public:
    string name;
    string city;
    int price;
    string country;

    Fruit(){}

    Fruit(string n,string c,int p){
        name = n;
        city  = c;
        country = "INDIA";
        price= p;
    }
    void print(){
        cout<<"F R U I T"<<endl;
        cout<<name<<endl;
        cout<<country<<endl;
        cout<<city<<endl;
        cout<<price<<endl;
    }



};

ostream& operator<<(ostream&os,Fruit f){
    f.print();
    return os;

}

int main(){

   map<string,Fruit> hf;


     Fruit f("Guava","Goa",100);
    Fruit f2("Mango","MP",200);
    Fruit f3("Pineapple","Punjab",60);

    pair<string,Fruit> p1(f.city,f);
    hf.insert(p1);

    hf["MP"] = f2;
    hf["Punjab"] =f3;

    string city;
    cin>>city;
    auto fs = hf.find(city);


    if(fs!=hf.end()){
        cout<<fs->first<<endl; /// Key
        cout<< fs->second <<endl; /// Fruit
    }
    else{
        cout<<"Not found "<<endl;
    }

    for(auto it=hf.begin();it!=hf.end();it++){
        cout<< it->second<<endl;
    }

return 0;
}
