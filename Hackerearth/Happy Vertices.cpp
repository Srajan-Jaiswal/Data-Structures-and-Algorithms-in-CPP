#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, n) for (int i = a; i < n; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define case cout << "Case " << t++ << ": ";
vector <int> Graph[100005]; 
int color[100005],
child[100005],
parent[100005]; 

void dfs(int v) { 
   color[v] = 1; 
   for(auto u : Graph[v]) { 
       if(color[u] == 0) { 
           parent[u] = v; 
           child[v]++; 
           dfs(u); 
       } 
   } 
   color[v] = 2; 
} 

int32_t main(){ 
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
   int n, m, a, b, ans = 0; 
   cin >> n >> m; 
   while(m--){ 
       cin >> a >> b; 
       Graph[a].pb(b); 
       Graph[b].pb(a); 
   } 
   fr(i, 1, n+1){ 
       dfs(i); 
   } 
   fr(i, 1, n+1){ 
       if(parent[i] != 0){ 
           if(child[parent[i]] < child[i]) ans++; 
       } 
   } 
   cout << ans << endl; 
}
