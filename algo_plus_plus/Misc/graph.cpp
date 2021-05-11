#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
	int V;
	unordered_map<int,vector<int> > l;

	
public:
	graph(int v){
		V = v;
	}
	void addedge(int u,int v,bool bidir = true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
		V = l.size();
		
	}
	
	
	void dfshelper(int src,unordered_map<int,bool> &visited){
		visited[src] = true;
		cout<<src<<" ";
		
		for(auto it = l[src].begin();it!=l[src].end();it++){
			if(!visited[*it]){
				dfshelper(*it,visited);
			}
		}
		
	}
	
	void dfs(){
		unordered_map<int,bool> visited;
		
		for(auto it = l.begin();it!=l.end();it++){
			if(!visited[it->first]){
				dfshelper(it->first,visited);
				cout<<endl;
			}
		}
	}
	
	void bfs(int src){
		unordered_map<int,bool> visited;
		
		queue<int> q;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			int f = q.front();
			cout<<f<<" ";
			q.pop();
			
			for(int i=0;i<l[f].size();i++){
				if(!visited[l[f][i]]){
				
					q.push(l[f][i]);
					visited[l[f][i]] = true;
				}
			}
		}
		
	}
	
};


int main(){
	graph g(8);
	
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(3,5);
	g.addedge(2,8);
	g.addedge(5,8);
	g.addedge(5,6);
	g.addedge(5,7);
	
	cout<<"DFS:"<<endl;
	g.dfs();
	cout<<"BFS:"<<endl;
	g.bfs(7);
	
	return 0;
}
