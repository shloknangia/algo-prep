#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<queue>
#define hashmap unordered_map<T,vector<T> >
using namespace std;

template<typename T>
class Graph{
    int V;
    hashmap l;

public:
    Graph(int v=0){
        V=v;
    }
    void addEdge(T u,T v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
        V = l.size();
    }

    void bfs(T src,T dest){
        unordered_map<T,bool> visited;
        unordered_map<T,int> distance;
        unordered_map<T,T> parent;
        for(auto it=l.begin();it!=l.end();it++){
            distance[it->first] = INT_MAX;
        }

        queue<T> q;

        q.push(src);
        visited[src]= true;
        distance[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T f  = q.front();
            cout<<f<<endl;
            q.pop();

            for(int i=0;i<l[f].size();i++){
                if(!visited[l[f][i]]){
                    distance[l[f][i]] = distance[f] + 1;
                    parent[l[f][i]] = f;
                    q.push(l[f][i]);
                    visited[l[f][i]] = true;
                }
            }

        }
        ///Print the distance
        cout<<"Distance from "<<src<<endl;

        for(auto it=l.begin();it!=l.end();it++){
            cout<<it->first<<"  - "<<distance[it->first]<<endl;
        }

        ///Path from src to dest
        T temp;
        cout<<"Path from src to dest "<<endl;
        temp = dest;
        while(temp!=src){
            cout<<temp<<"<---";
            temp = parent[temp];
        }
        cout<<src<<endl;

    }

    void printAdjList(){
        for(auto i=l.begin();i!=l.end();i++){

            T current = i->first;
            cout<<current<<"->";
            for(int j=0;j<l[current].size();j++){
                    cout<<l[current][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Delhi","Agra");
    //g.addEdge("Delhi","Jaipur");
    g.addEdge("Jaipur","Bhopal");
    g.addEdge("Agra","Jaipur");
    g.addEdge("Mumbai","Agra");
    g.addEdge("Delhi","Mumbai");

    g.printAdjList();
    string c1,c2;
    cin>>c1>>c2;

    g.bfs(c1,c2);


return 0;
}
