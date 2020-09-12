#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
   list<int> *l;
    int v;
    public:
    Graph(int v)
    {
        this->v=v;
     l=new list<int>[v];
    }
    void addEdge(int U,int V,bool bidrc=true)
    {
        list[U].push_back(V);
        if(bidrc)
        {
            list[V].push_back(U);
        }   
    }
    void bfs(int src, int ver )
    {
      list<bool> *visited;
      visited=new bool[v]
      list<int> *level;
      level=new int[v]
      for(int i;i<v;i++)
      {
          visited[i]=false;
          level[i]=0;
      }
      queue<int> q;
      q.push(src);
      visited[src]=true;
      level[src]=0;
      while(!q.empty())
      {
          int node=q.front();
          cout<<node<<" ";
          q.pop();
          for(auto nbr: list[node])
          {
              if(!visited[nbr])
              {
                  visited[nbr]=true;
                  level[nbr]=level[src]+1;
              }
          }
          
      }
      for(auto itr: level[v])
      {
          cout<<level[ver];
      }
    }
};
int main()
{
 Graph g(8);
 g.addEdge(0,1);
 g.addEdge(1,3);
 g.addEdge(1,4);
 g.addEdge(1,5);
 g.addEdge(0,2);
 g.addEdge(2,6);
 g.addEdge(6,7);
 bfs(0,4);
 return 0;
}






