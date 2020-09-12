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
	}

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

}