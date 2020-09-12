#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class Graph
{
  map<T,list<int>> adjList;
  public:
  	Graph()
  	{

  	}

void addEdge(T U,T V, bool bidrc)
{
  adjList[u].push_back(v);
  if(bidrc)
  {
  	adjList[v].push_back(u);
  }
}
void bfs(T src, T dest)
{
	queue<T> q;
	map<T,int> dist>;
	map<T,T> parent;
	for(auto i:dist)
	{
		dist[it.first]=INT_MAX;
	}
	dist[src]=0;
    parent[src]=src;
    q.push(src);
	while(!q.empty())
	{
		T node=q.front();
		q.pop();

		for(auto nbr:adjList[node]) // it basically traverses your particular node's list of values
		{
         if(dist[nbr]==INT_MAX)
         {
             dist[nbr]=dist[node]+1;
             parent[nbr]=node;
         }  
		}
	}
	for(auto i1:adjList)
	{
		T node=i.first;
		cout<<"dist "<<"of "<<node<<" is "<<dist[node]<<endl;
	}
	return dest[dest];
}
};
int main()
{
  Graph<int> g;
  int board[] ={0};
  board[2]=13;
   board[5]=2;
   board[9]=18;
    board[18]=11;
     board[17]=-13;
      board[20]=-14;
       board[24]=-8;
        board[25]=-10;
         board[32]=-2;
          board[34]=-22;
          for(u=0; u<=35;uv++)
          {
          	 for(dice=0;dice<=6;dice++)
          	 {
          	int = u+dice +board[u+dice];
          	g.addEdge(u,v,false);
          }
      }
      cout<<"the shortest bfs is"<<g.bfs(0,36);
      return 0;
}