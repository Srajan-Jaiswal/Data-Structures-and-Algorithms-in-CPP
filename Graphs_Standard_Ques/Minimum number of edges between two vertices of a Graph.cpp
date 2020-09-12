#include<iostream>
#include<queue>
#include<map>
#include<list>
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

 void addEdge(int U,int V)
 {
 	l[U].push_back(V);
 	l[V].push_back(U);
 }   
 int bfs_min_dis(int src,int dest)
 {
 	queue<int> q;
 	map <int,bool> visited;
 	map <int,int> distance;
 	visited[src]=false;
 	distance[src]=0;
 	q.push(src);
 	visited[src]=true;
 	while(!q.empty())
 	{
 		int node=q.front();
 		q.pop();
 		for(auto nbr:l[node])
 		{
 			if(!visited[nbr])
 			{
 				q.push(nbr);
 				visited[nbr]=true;
 				distance[nbr]=distance[node]+1;
 			}
 		}
 	}
 	return distance[dest];
 }
};
int main()
{
	Graph g(9);
	g.addEdge(0, 1); 
    g.addEdge(0, 7); 
    g.addEdge(1, 7); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 5); 
    g.addEdge(2, 8); 
    g.addEdge(3, 4); 
    g.addEdge(3, 5); 
    g.addEdge(4, 5); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8);
    cout<<endl;
    cout<<g.bfs_min_dis(0,5)<<endl;
 return 0;
}