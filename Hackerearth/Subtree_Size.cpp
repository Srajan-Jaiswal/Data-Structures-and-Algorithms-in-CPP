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

vector<int> adjlist[1001];
int vis[1001];
int sub_size[1001];

int dfs(int src)
{
    vis[src] = 1;
    int curr = 1;
    for (int nbr : adjlist[src])
    {
        if (vis[nbr] == 0)
        {
            curr += dfs(nbr);
        }
        sub_size[src] = curr;
        return curr;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i < n; i++)
        {
            adjlist[i].clear();
            vis[i] = 0;
            sub_size[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjlist[u].pb(v);
            adjlist[v].pb(u);
        }
        dfs(1);
        cout << sub_size[1] << endl;
    }
}
