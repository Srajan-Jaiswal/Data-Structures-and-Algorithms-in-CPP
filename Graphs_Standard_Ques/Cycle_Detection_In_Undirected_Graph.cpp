#include <bits/stdc++.h>
using namespace std;
class Graph
{
  list<int> *l;
  int v;
public:
	Graph(int v)
	{
     this->v=v;
     l= new list<int>[v];
	}

void addEdge(int U,int V, bool bidrc=true)
{
	l[U].push_back(V);
	if(bidrc)
	{
		l[V].push_back(U);
	}
}	
bool itr_cycle(int node, bool *visited, int parent)
{
  visited[node]=true;
  
  for(auto nbr: l[node])
  {
  	if(!visited[nbr])
  	{
  		return true;
  	}
  	else if(visited[nbr]==false)
  	{
        bool cycle_mila = itr_cycle(nbr,visited,node); //dfs
  	    if(cycle_mila)
    	{
  		    return true;
  	    }
  	}
  }
  return false;
}
bool is_cycle()
{
    bool vi[100001];
    return itr_cycle(0,vi,0);
}
};

int main()
{
 Graph  g(5);
	 g.addEdge(0,1);
	 g.addEdge(1,2);
	 g.addEdge(0,4);
	 g.addEdge(2,4);
	 g.addEdge(2,3);
	 g.addEdge(3,5);
	 g.addEdge(3,4);
	 cout<<endl;
	 g.is_cycle();
	 return 0;
}
