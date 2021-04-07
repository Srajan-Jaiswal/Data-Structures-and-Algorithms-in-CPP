#include<iostream>
using namespace std;
class Graph:
{
  list<int> *l;
  int v;
public:
	Graph(int v)
	{
     this->v=v;
     l= new list<int>[v];
	}#include<iostream>
using namespace std;
class Graph:
{

void addEdge(int U,int V, bool bidrc=true)
{
	list[U].push_back(V);
	if(bidrc)
	{
		list[V].push_back(U);
	}
}	
bool itr_cycle(int node, bool *visited, bool *stack)
{
  visited[node]=true;
  stack[node]=true;
  // DFS (maintaing stack for detecting back  edge and visted array)
  for(auto nbr: l[node])
  {
  	if(stack[nbr]==true)
  	{
  		return true;
  	}
  	else if(visited[nbr]==false)
  	{
  		bool cycle_mila=itr_cycle(nbr,visited,stack);
  	if(cycle_mila)
  	{
  		return true;
  	}
  	}
  }
  stack[node]=false;
  return false;
}
void is_cycle()
{
  bool visited=new bool[v];
  bool stack=new bool[v];
 return itr_cycle(0,visited,stack)
}
};

int main()
{
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
	 g.dfs_topological();
	 return 0;
}
