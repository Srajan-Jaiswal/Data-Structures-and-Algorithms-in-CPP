#include<iostream>
#include<map>
using namespace std;
class Graph
{
	list<int> *l;
	int v;
 public:
  Graph(int v)
  {
  	this->v=v;
  	l= new list<int>[v];  //array of linked list representation
  }
  void addEdge(int U, int V)
  {
  	l[U].push_back(V);
  	l[V].push_back(U);
  }

  bool istree(int src)
  {
  	map<int,bool> visited;
  	map<int,int> parent;
  	queue<int> q;
  	visited[src]=false;
  	parent[src]=0;
  	q.push(src);
  	visited[src]=true;
  	while(!q.empty())
  	{
  		int node=q.front();
  		cout<<node<<" ";
  		q.pop();
  		for(auto nbr: l[node])
  		{
  		if(visited[nbr]=true && parent[node]!=nbr)
  		{
  			return false;
  		}
  		else if(!visited[node])
  		{
  		   visited[nbr]=true;
  		   parent[nbr]=node;
  		   q.push_back(nbr);
  		}
  	}
  	}
  }
};