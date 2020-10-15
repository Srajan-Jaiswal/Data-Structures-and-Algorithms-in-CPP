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
vector<int> vis;
vector<int> dis;

void dfs(int f, int d)
{
    vis[f] = 1;
    dis[f] = d;
    for (int i : adjlist[f])
    {
        if (vis[i] == 0)
        {
            dfs(i, dis[f] + 1);
        }
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
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].pb(v);
        adjlist[v].pb(u);
    }
    for (int i = 1; i < 1001; i++)
    {
        vis.pb(0);
        dis.pb(0);
    }
    dfs(1, 0);
    cin >> q;
    int maxi = INT_MAX;
    int ans = -1;
    while (q--)
    {
        int g;
        cin >> g;
        if (dis[g] < maxi)
        {
            maxi = dis[g];
            ans = g;
        }
        else if (dis[g] == maxi && g < ans)
        {
            ans = g;
        }
    }
    cout << ans << endl;
}
