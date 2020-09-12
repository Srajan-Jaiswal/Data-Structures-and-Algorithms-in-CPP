#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph
{
	map<T, list<T>> adjList;
public:
	Graph()
	{

	}
void addEdge( T U, T V, bool bidrc=false)
{
	adjList[U].push_back(V);
	if(bidrc)
	{
    adjList[V].push_back(U);
	}
}
void print()
{
	for(auto it1: adjList)
	{
		cout<<it1.first<<"-->>";
		for(auto it2: it1.second)
		{
			cout<<it2<<" ";
		}
		cout<<endl;
	}

}
void dfs_help(T node,map<T,bool> &visited, list<T> &ordering)
{
	visited[node]=true
   
   for(auto nbr: adjList[node])
   {
   	 if(!visited[nbr])
   	 {
   	 	dfs_help(nbr,visited,ordering);
   	 }
   }
   	 // for topological sort
   	 // at this point all the children of the node is visited acc. to  yor dfs algorithm 
    ordering.push_front(node); // Try to understand here we when we reached to  the node where no more nodes are left then recursive step is being over and then we push_front() that node in  linked list..
}
void dfs_topological()
{
	map<T,bool> visited;
	list<T> ordering;
	for(auto i:adjList)
	{
		 T node=i.first;
		 if(!visited[node])
		 {
		 	dfs_help(node,visited,ordering);
		 }
	}
	// print the list
	for(auto ele: ordering)
	{
		cout<<ele<<"--->>";
	}
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
	 g.dfs_topological();
	 return 0;
}