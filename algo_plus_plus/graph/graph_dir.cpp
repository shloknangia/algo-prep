#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
	int V;
	list<pair<int, int> > *l;
public:
	graph(int v){
		V =v;
		l = new list<pair<int ,int> > [V];
	}
	
	void addedge(int u,int v,int w,int bidir = true){
		
		l[u].push_back(make_pair(v,w));
		if(bidir){
			l[v].push_back(make_pair(u,w));
		}
	}
	
	void dijkstra(int src){
		
		int *dist = new int[V];
		for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
        }
		set<pair<int,int> > s;
		dist[src] = 0;
		s.insert(make_pair(0,src));
		
		while(!s.empty()){
			auto it = s.begin();
			int parent = it->second;
			int parentDist = it->first;
			s.erase(it);
			
			for(auto i = l[parent].begin();i != l[parent].end();i++){
				
				if(parentDist + i->second < dist[i->first]){
					int oldDist = dist[i->first];
					auto f = s.find(make_pair(oldDist,i->first));
					if(f!=s.end()){
						s.erase(f);
					}
					dist[i->first] = parentDist + i->second;
					s.insert(make_pair(dist[i->first],i->first));
				}
			}
			
		}
		
		for(int i=0;i<V;i++){
			cout<<i<<" == "<<dist[i]<<endl;
		}
		
	}
	
	
};


int main(){
	
	graph g(6);
    g.addedge(0,1,1);
    g.addedge(0,4,6);
    g.addedge(4,2,1);
    g.addedge(4,5,7);
    g.addedge(4,1,3);
    g.addedge(1,2,4);
    g.addedge(2,3,3);
    g.addedge(3,5,2);

    g.dijkstra(0);
	return 0;
}
