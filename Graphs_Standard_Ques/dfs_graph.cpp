#include<iostream>
#include<list>
#include<map>
using namespace std;
 template<typename T>
 class Graph
 {
 	map<T,list<T>> adjList;
 public:
 	Graph()
 	{

 	}

 
void addEdge(T U, T V, bool bidrc=false)
{
	adjList[U].push_back(V);
	if(bidrc)
	{
	adjList[V].push_back(U);
    }
}
void print()
{
 for(auto it:adjList)
 { 
 	cout<<it.first<<"-->>";
 	for(auto it1:it.second)
 	{
 		cout<<it1<<",";
 	}
  
     cout<<endl;
 }
} 
void dfs_helper(T node,map<T, bool> &visited)
{
    // base case
   if(visited[node]= true)
   {
	 cout<<node<<" ";
   }
   // recursive step
	for(auto nbr: adjList[node])
	if(!visited[nbr])
	{
		dfs_helper(nbr, visited); // we recursively check that whether the nodes are visited or not.
	}
}
void dfs(T src)
{
map<T,bool> visited;
dfs_helper(src,visited); 
}
};
int main()
{
	 Graph <int> g;
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
	 return 0;
}



  







