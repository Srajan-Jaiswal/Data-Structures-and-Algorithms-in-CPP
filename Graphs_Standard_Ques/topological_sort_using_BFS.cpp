#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;
template <typename T>
class Graph
{
	map<T, list<T>> adjList;
public:
	Graph()
	{

	}

void addEdge(T U , T V, bool bidrc)
{
  adjList[U].push_back(v);
  if(bidrc)
  {
  adjList[V].push_back(U);
  }
}

void print()
{
	for(auto it: adjList)
		{
			cout<<it.first<<"-->>";
			for(auto it2: it.second)
			{
				cout<<it2<<" ";
			}
			cout<<endl;
		}
}
void bfs_topological()
{
	queue <T> q;
	map<T,bool> visited;
	map<T,int> indeg;

	for(auto i: adjList) // here it is the iterator which is pair of node and its lists
	{
		T node=i.first;
		visited[node]=false;
	    indeg[node]=0;
	}

	// initialise the indegrees
	for(auto m:adjList) // we iterate over the whole adjlist node
	{
		T U = m.first;
		for(auto V: adjlist[U])// here we iterate for the linked list of each v
	      indeg[V]++;   // here we update the map of indegree and with the value of indegree ofeach vertex
	}
    
    // search for the indegrees having value 0
    for(auto it: adjlist)
    {
    	T node=it.first;
    	if(indeg[node]== 0)
    	{
    		q.push(node);
    	}
    }

    while(!q.empty())
    {
    	T node=q.front();
    	q.pop();
    	cout<<node<<-->>;
    	for(auto nbr: adjlist[node])
    	{
    		indeg[node]--;
    		if(indeg[nbr]==0)
    		{
    			q.push(nbr);
    		}
    	}
    }
}
}
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
	 g.bfs_topological();
	 return 0;
}