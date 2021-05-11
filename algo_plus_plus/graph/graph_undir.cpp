#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

class graph{
	int V;
	list<int> *l;
public:

	graph(int v){
		V = v;
		l = new list<int>[V];
	}
	
	void addedge(int u,int v,bool bi = true){
		l[u].push_back(v);
		if(bi){
			l[v].push_back(u);
		}
		
	}
	
	void print(){
		for(int i=0;i<V;i++){
			cout<<i<<" -> ";
			for(auto it = l[i].begin();it!=l[i].end();it++){
				cout<<*it<<", ";
			}
			cout<<endl;
			
		}
	}
	
	
	void bfs(int src){
		
		map<int,bool> visited;
		queue<int> q;
		
		q.push(src);
		visited[src] = true;
		
		while(!q.empty()){
			
			int t = q.front();
			cout<<t<<" ";
			q.pop();
			
			for(auto it = l[t].begin();it!=l[t].end();it++){
				if(!visited[*it]){
					visited[*it] = true;
					q.push(*it);
				}
			}
			
		}
		
	}
	
	
	void dfshelper(int n,map<int,bool> &visited){
		
		visited[n] = true;
		cout<<n<<" ";
		
		for(auto it = l[n].begin();it!=l[n].end();it++){
			if(!visited[*it]){
				dfshelper(*it,visited);
			}
			
		}
		
		
	}
	
	
	void dfs(int src){
		
		map<int,bool> visited;
		
		dfshelper(src,visited);
		
		for(auto it = l->begin();it!=l->end();it++){
			
			if(!visited[*it]){
				
				dfshelper(*it,visited);
				cout<<endl;
			}
			
		}
		
	}
	
	void topological(){
		
		int *indeg = new int[V] {0};
		
		for(int i=0;i<V;i++){
			for(auto it = l[i].begin();it!=l[i].end();it++){
				indeg[*it]++;
			}
		}
		queue<int> q;
		
		for(int i=0;i<V;i++){
			if(indeg[i] == 0){
				q.push(i);
			}
		}
		
		while(!q.empty()){
			
			int temp = q.front();
			q.pop();
			
			cout<<temp<<" ";
			
			for(auto it = l[temp].begin();it!=l[temp].end();it++){
				
				indeg[*it]--;
				if(indeg[*it] == 0){
					q.push(*it);
				}
			}
		}
		
	}
	
	int findP(int x,int parent[]){
		
		if(parent[x] == x){
			return x;
		}
		return findP(parent[x],parent);
		
	}
	
	void Union(int x,int y,int parent[]){
		
		int xp = findP(x,parent);
		int yp = findP(y,parent);
		
		parent[yp] =xp;
		
	}
		
	bool isCyclicUndir(){
		
		int *parent = new int[V];
		for(int i=0;i<V;i++){
			parent[i] = i;
		}
		
		for(int i=0;i<V;i++){
			for(auto it =l[i].begin();it!=l[i].end();it++){
				
				int x = i;
				int y = *it;
				
				int xParent = findP(x,parent);
				int yParent = findP(y,parent);
				
				if(xParent == yParent){
					return true;
				}
				Union(x,y,parent);
			}
		}
		return false;
		
	}
	
	
	bool isCyclicHelper(int n,bool visited[],bool inStack[]){
		
		visited[n] = true;
		inStack[n] = true;
		
		for(auto it = l[n].begin();it != l[n].end();it++){
			
			if(!visited[*it] && isCyclicHelper(*it,visited,inStack)){
				return true;
			}
			else if(inStack[*it]){
				return true;
			}
			
		}
		inStack[n] = false;
		return false;
		
	}
	
	bool isCyclicDir(){
		
		bool *visited = new bool[V]{false};
		bool *inStack = new bool[V]{false};
		
		for(int i=0;i<V;i++){
			if(isCyclicHelper(i,visited,inStack)){
				return true;
			}
			
		}
		return false;		
		
	}
	
	
	
	
	
};


int main(){
/*	graph g(5);


    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(3,4);
    g.addedge(2,3);
    g.addedge(4,0);

	g.print();
	cout<<endl;
	g.bfs(1);
	cout<<endl;
	g.dfs(2);
	*/
	
	
	graph g(6);
    g.addedge(0,2,false);
    g.addedge(0,3,false);
    g.addedge(1,2,false);
    g.addedge(2,3,false);
    g.addedge(3,4,false);
    g.addedge(3,5,false);
    g.addedge(2,5,false);
    g.addedge(4,5,false);

	g.print();
	cout<<endl;
    g.topological();
    
    cout<<endl;
    cout<<g.isCyclicUndir();
    cout<<endl;
    cout<<g.isCyclicDir();
	return 0;
}
