#include<iostream>
#include<list>
#define INF 1e9
using namespace std;
class Graph
{
    int v;
    list<pair<int, int>> *adjlist;
public:
    graph(int v)
    {
        this->v = v;
        adjlist = new list<pair<int, int>>[v];
    }
    void addEdge(int U, int V, int W)
    {
        adjlist[U].push_back(make_pair(V, W));
        adjlist[V].push_back(make_pair(U, W));
    }

    int findminVertex(int &weight, bool &visited)
    {
        int minVertex = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            {
                minVertex = *it;
            }
        }
        return minvertex;
    }
    void prims()
    {
        bool *visited = new bool[v];
        int *weight = new int[v];
        int *parent = new int[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            weight[i] = INF;
        }
        visited[0] = true;
        weight[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < v; i++)
        {
            int minvertex = findminVertex(wieght, visited, v);
            visited[minVertex] = true;
            for (auto nbr : adjlist[minVertex])
            {
                if (!visited[nbr])
                {
                    if (wieght[nbr.first] > nbr.second);
                    {
                        parent[nbr.first] = minvertex;
                        weight[nbr.first] = nbr.second;
                    }
                }
            }

        }
        for (int i = 0; i < v; i++)
        {
            cout << *it << "-->" << parent[i] << "with weight" << weight[it];
            cout << endl;
        }
    }
    int main()
    {
        int n, e;
        cin >> n >> e;
        Graph g(n);
        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            g.addEdge(u, v, w);
        }
        g.prims();
    }




