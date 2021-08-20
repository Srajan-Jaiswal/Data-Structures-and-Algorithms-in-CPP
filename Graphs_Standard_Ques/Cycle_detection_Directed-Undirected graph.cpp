// UNDIRECTED

class Solution 
{
    public:
    
    bool find_cycle(int node,vector<int> adj[],vector<bool> &vis,int parent){
        vis[node] = true;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                bool is_cycle = find_cycle(nbr,adj,vis,node);
                if(is_cycle) return true;  
            }
            else if(nbr != parent || nbr == node){
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	   vector<bool> vis(V,false);
	   for(int i=0;i<V;i++){
	       if(!vis[i] && find_cycle(i,adj,vis,-1))return true;
	   }
	   return false;
	}
};



// Directed 

class Solution 
{
    public:
    
    bool find_cycle(int node,vector<int> adj[],vector<bool> &vis,int parent){
        vis[node] = true;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                bool is_cycle = find_cycle(nbr,adj,vis,node);
                if(is_cycle) return true;  
            }
            else if(nbr != parent || nbr == node){
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	   vector<bool> vis(V,false);
	   for(int i=0;i<V;i++){
	       if(!vis[i] && find_cycle(i,adj,vis,-1))return true;
	   }
	   return false;
	}
};
