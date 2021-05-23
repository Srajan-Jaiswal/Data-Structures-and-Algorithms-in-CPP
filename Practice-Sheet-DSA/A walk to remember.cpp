#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
bool special_walk(int node,int n,vector<bool> &stack,vector<bool> &vis){
    vis[node] = true;
    stack[node] = true;
    for(auto it : arr[node]){
        if(stack[it]) return true;
        else if(!vis[it]){
            bool cycle = special_walk(it,n,stack,vis);
            if(cycle) return true;
        }
    }
    stack[node]=false;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        vector<bool> vis(n+1,false);
        vector<bool> stack(n+1,false);
       cout<<special_walk(i,n,stack,vis)<<" ";
    }

}
