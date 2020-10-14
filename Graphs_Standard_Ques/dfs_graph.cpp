#include<iostream>
#include<list>
#include<map>
using namespace std;
 class Graph
 {
 	list<int>* adjList;
 	int v; // number of vertices
 public:
 	Graph(int v)
 	{
       this->v=v;
      adjList= new list<int>[v]; 
 	}

void addEdge(int U, int V, bool bidrc=true)
{
	adjList[U].push_back(V);
	if(bidrc)
	{
	adjList[V].push_back(U);
    }
}
void print()
{
 for(int it =0 ;it<v;it++)
 { 
 	cout<<it<<"-->>";
 	for(auto it1: adjList[it])
 	{
 		cout<<it1<<",";
 	}
     cout<<endl;
 }
} 
void dfs_helper(int node,map<int, bool> &visited)
{
    // base case
   if(visited[node]= true)
   {
	 cout<<node<<" ";
   }
   visited[node] = true;
   // recursive step
	for(auto nbr: adjList[node])
	if(!visited[nbr])
	{
		dfs_helper(nbr, visited); // we recursively check that whether the nodes are visited or not.
	}
}
void dfs(int src)
{
map<int,bool> visited;
dfs_helper(src,visited); 
}
};
int main()
{
	 int v;
	 Graph  g(v);
	 g.addEdge(0,1);
	 g.addEdge(1,2);
	 g.addEdge(0,4);
	 g.addEdge(2,4);
	 g.addEdge(2,3);
	 g.addEdge(3,5);
	 g.addEdge(3,4);
	 g.print();
	 cout<<endl;
	 g.dfs(0);
	 g.print();
	 return 0;
}

