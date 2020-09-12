#include<iostream>
#include<queue>
#include<list>
#include<map>
#include<climits>
#include<cmath>
using namespace std;
template<typename T>
class Graph
{
	map<T,list<T>> adjlist;
public:
	Graph()
	{

	}

void addEdge(T U, T V, bool bidrc=true)
{

	adjlist[U].push_back(V);
	if(bidrc)
	{
    adjlist[V].push_back(U);
	}
}
void print()
{
	for(auto it:adjlist)
	{
		cout<<it.first<<"-->";
		for(auto j: it.second)
		{
			cout<<j<<",";
		}
		cout<<endl;
	}
}
void bfs(T src)
{
	queue<T> q; 
	map<T,int> dist; // a map for storing distance of every node 
	map<T,T> parent; 
     
    for(auto it:adjlist)
    {
    	dist[it.first]= INT_MAX; // this loop actually make ditance of each node in adjlist maps key to infinity
    }
	q.push(src);
	dist[src]=0;
	parent[src]=src; 
	while(!q.empty())
	{
		T node=q.front();  // jab tak q empty nahi ho jata tab tak 
		cout<<node<<" ";  // for printing the bfs order of a  tree
		q.pop();

	 for(int neigbour: adjlist[node]) // here the adjlist[node] is basically tells us that the  value of the key node in map adjlist  i.e(the adjacent nodes to the node) 
	 { 
	 	if(dist[neigbour] == INT_MAX)
	 	{
	 		q.push(neigbour);
	 		dist[neigbour]=dist[node]+1;
            parent[neigbour]=node; 
	 	}
	 }
	}
	// print the distance to all nodes
	for(auto i:adjlist)
	{
      T node= i.first;
      cout<<endl;
      cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
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
	 g.bfs(0);
	 return 0;
}000