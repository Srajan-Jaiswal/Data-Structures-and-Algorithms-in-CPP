#include<iostream>
#include<list>
#include<map>
#include<string>
using namespace std;
template<typename T>
class Graph
{
  map<T, list<T>> adjlist;
public:
  Graph()
  {

  }
  void addEdge(T u, T v, bool bidrc = true)
  {
    adjlist[u].push_back(v);
    if (bidrc)
    {
      adjlist[v].push_back(u);
    }
  }
  void print()
  {
    for (auto it1 : adjlist)
    {
      cout << it1.first << "--->>";
      for (auto it2 : it1.second)
      {
        cout << it2 << " ";
      }
      cout << endl;
    }
  }
  void dfs_rec(T node, map<T, bool> &vis_nodes)
  {
    vis_nodes[node] = true;
    cout << node << " ";
    for (auto nbr : adjlist[node])
    {
      if (!vis_nodes[node])
      {
        dfs_rec(nbr, vis_nodes);
      }
    }
  }

  void dfs(T src)
  {
    map<T, bool> vis_nodes;
    int component = 1;
    dfs_rec(src, vis_nodes);
    cout << endl;

    for (auto itr : adjlist)
    {
      T city = itr.first;
      if (!vis_nodes[city])
      {
        dfs_rec(city, vis_nodes); // actually this is basically the 2nd component in whic we check that is there more components inside it
        component++;
      }
    }
    cout << "THE CURRENT GRAPH HAD" << component << "components";
  }
};
int main()
{
  Graph<string> g;
  g.addEdge("AMRITSAR", "JAIPUR");
  g.addEdge("AMRITSAR", "DELHI");
  g.addEdge("DELHI", "JAIPIUR");
  g.addEdge("MUMBAI", "JAIPUR");
  g.addEdge("MUMBAI", "BHOPAL");
  g.addEdge("DELHI", "BHOPAL");
  g.addEdge("MUMBAI", "BANGALORE");
  g.addEdge("AGRA", "DELHI");
  g.addEdge("ANDAMAN", "NICOBAR");
  g.print();
  g.dfs("AMRITSAR");
  return 0;
}

