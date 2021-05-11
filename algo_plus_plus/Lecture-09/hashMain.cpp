#include<iostream>
#include "hashtable.h"
using namespace std;

# define mp make_pair<string,int>

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



};

int main(){
    /*
    hashTable<pair<string,int> > h;

    h.insert("Mango",mp("Delhi",120));

    h.insert("kiwi",mp("Himachal",140));

    h.print();

    string fruit;
    cin>>fruit;

    pair<string,int> *price = h.search(fruit);
    if(price!=NULL){

        cout<<"Fruit costs "<< price->second <<endl;
        cout<<"Fruit comes from "<< price->first<<endl;
    }
    else{
        cout<<"Nahi mila "<<endl;
    }
    */

    hashTable<Fruit> hf;

    Fruit f("Guava","Goa",100);
    Fruit f2("Mango","MP",200);
    Fruit f3("Pineapple","Punjab",60);

    hf.insert(f.city,f);
    hf.insert(f2.city,f2);
    hf.insert(f3.city,f3);

    hf.print();

    string city;
    cin>>city;

    Fruit *fs = hf.search(city);
    if(fs){
        cout<<fs->name<<endl;
        cout<<fs->price<<endl;
    }




return 0;
}
