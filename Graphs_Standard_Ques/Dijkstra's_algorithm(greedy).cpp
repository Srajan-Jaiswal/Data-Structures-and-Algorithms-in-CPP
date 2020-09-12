#include<iostream>
#include<unordered_map>
#include<cmath.h>
using namespace std;
template<typename T>
class Graph
{
    unordered_map<T, pair<T, int>> m;
public:
    Graph()
    {

    }
    void addedge(T U, T V, int dis, bool bidrc = false)
    {
        m[U].push_back(make_pair(V, dist));
        if (bidrc)
        {
            m[V].push_back(make_pair(U, dist));
        }
    }
    void print()
    {
        for (auto it : m)
        {
            cout << it.first << "-->";
            for (auto itr : it.second)
            {
                cout << "(" << itr.first << "," << itr.second << ")";
            }
            cout << endl;
        }
    }
// function for dijkstra's algorithm which  returns the distances of each nodes
    void dijkstra(T src)
    {
        unordered_map<T, int> dis; // map for distance
        for (auto i : m)
        {
            dis[i.first] = INT_MAX;
        }
        // it is a set of pair of nodes and their min distances
        set<pair<int, T>> min_dis; // a pair which stores the updated distance of the nodes and btw int is first in map jus because we want the sorting wrt to distance
        dis[src] = 0;
        min_dis.insert(make_pair(0, src));
        while (!min_dis.empty())
        {
            auto p = *(min_dis.begin()); // give the begining pair
            // btw here we stored the information of the prev node from which we have to go to the dest.
            T node = p.second;
            int nodeDist = p.first;
            min_dis.erase(min_dis.begin());

            for (auto c_p : m[node]) // iterating on the adjacency list of the node(i.e p.second)
            {
                if (nodeDist + c_p.second < dis[c_p.first])
                {
                    T dest = c_p.first;
                    auto f = min_dis.find(make_pair(dis[dest], dest));
                    if (f != min_dis.end())
                    {
                        min_dis.erase(f);
                    }
                    // update for the updated distance in dis hashmap and the set pair;
                    dis[dest] = nodeDist + c_p.second;
                    min_dis.insert(make_pair(dis[dest], dest));
                }

            }
        }
    }

}
int main()
{

}