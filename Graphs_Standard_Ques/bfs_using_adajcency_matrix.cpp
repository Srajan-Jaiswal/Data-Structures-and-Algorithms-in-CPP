#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Graph
{
	int v;
	int e;
	int **adj_mat
public:
	Graph(int v,int e);

	void addEdge(int U,int V, bool bidrc);

	void bfs(int start);

};
Graph:: Graph(int v,int e)
{
	this->v=v;
	this->e=e;
	adj_mat= new int*[v];
	for(int i=0;i<v;i++)
	{
	   adj_mat[i]= new int[v];
	   for(int j=0;j<v;j++)
	   {
	   	adj_mat[i][j]=0;
	   }
	}
}

Graph:: addEdge(int U, int V, bool bidrc)
{ 
	// condition of birectional
	adj_mat[U][V]=1;
	adj_mat[V][U]=1;
}

Graph:: bfs(int start)
{
  map<int,bool> visited;
  queue<int> q;
  q.push(start);
  visited[start]= true;
   
  while(!q.empty())
  {  
  int node= q.front();
  cout<<node<<" ";
  q.pop();
    
  for(int nbr=0;nbr<v,nbr++)
  {
  	if(adj_mat[node][nbr] && (!visited[nbr]))
  	{
  		q.push(nbr);
  		visited[nbr]=true;
  	}
  }
  }
}
int main()
{
	int v=5,e=4;
	Graph G(v,e);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,3);
   G.bfs(0);
}
