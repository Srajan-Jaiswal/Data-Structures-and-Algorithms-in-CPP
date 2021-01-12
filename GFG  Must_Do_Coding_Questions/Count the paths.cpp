https://practice.geeksforgeeks.org/problems/count-the-paths/0/?category[]=Graph&category[]=Graph&difficulty[]=0&page=1&query=category[]Graphdifficulty[]0page1category[]Graph

#include<bits/stdc++.h>
using namespace std;

void DFSRec(vector<int> adj[], int u, int s, int d, vector<bool> visited, int &count)
{
    if(u == d)
    {
        count++;
        return;
    }
    
    for(auto v: adj[u])
    {
        if(visited[v] == false)
        {
            visited[v] = true; 
            
            DFSRec(adj, v, s, d, visited, count);
            
            visited[v] = false;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int V, E;
        cin >> V >> E;
        
        vector<int> adj[V];
        
        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            
            adj[u].push_back(v);
        }
        
        int s, d;
        cin >> s >> d;
        
        vector<bool> visited(V, false);
        int count = 0;
        visited[s] = true;
        
        DFSRec(adj, s, s, d, visited, count);
        
        cout << count << endl;
    }
    return 0;
}
