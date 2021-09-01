void dfs(int u, vector<int> G[], vector<bool> &visited, stack<int> &s, bool topo){
    
    visited[u] = true;
    
    for(auto &v: G[u])
        if(!visited[v])
            dfs(v, G, visited, s, topo);
    
    if(topo)
       s.push(u);
    
}

int kosaraju(int n, vector<vector<int>> G)
{
    
    vector<vector<int>> RG(n);
    stack<int> s;
    
    vector<bool> visited(n, false);
    
	// Step 1: Store vertices in Topological Sort order
    for(int u=0;u<n;u++)
        if(!visited[u])
            dfs(u, G, visited, s, true);
    
	// Step 2: Reverse all edges of the Graph
	for(int u=0;u<n;u++)
        for(auto &v: G[u])
            RG[v].push_back(u);
    
    visited = vector<bool>(V, false);
	
	// Step 3: One by One pop elements from top of the stack and Count/Store and Mark the elements visited by current vertex
	int scc = 0;
    while(!s.empty()){
        auto u = s.top();
        s.pop();
        if(!visited[u]){
            dfs(u, RG, visited, s, false);
            scc++;
        }
    }
    
    return scc;
    
}
