#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Graph
{
    map<int, list<int>> adjList;
    int v;
}
public:
Graph(int v)
{
 this->v=v;   
}

void addEdge(int U, int V, bool bidrc)
{
    adjList[U].push_back(V);
    if(bidrc)
    {
        adjList[V].push_back(U);
    }
}
void BFS(int src, int *visited)
{
    queue<int> q;
    bool *visited;
    visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto nbr: adjlist[node])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }
}
void bfs(int src)
{
    bool *visited;
    visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    if(visited[i]==false)
    {
        BFS(i,visited);
    } 
    }
}