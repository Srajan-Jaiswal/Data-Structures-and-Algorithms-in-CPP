//Algorithm:
//1.>  make a graph class
//2.>  write a function to add edges and print them
//3.>  in bfs function we firstly make a queue and  insert src in it
//4.>  make a map of visited which tells us that whether the node is visited or not... 

#include<iostream>
#include<map>
#include<list>
#include<queue>
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
	cout<<it.first<<"-->>";
    for(auto it1:it.second)
    {
     cout<<it1<<",";
    }
    cout<<endl;
}
}
void bfs(T src)
{
	queue<T> q;
	map<T,bool> visited;   //  it's a hash map simple in which has key T and it check for the whether the node is visited or not
    q.push(src);
  visited[src]= true;
  while(!q.empty())
  {
  	T node=q.front();
  	cout<<node<<" ";
  	q.pop();
  	// 
  	for(auto nbr:adjlist[node])
  	{
  		if(!visited[nbr])
  		{
  			q.push(nbr);
  		    visited[nbr]= true;
  	    }
  	}

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
}