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

vector<int> adjlist[1000001];
int vis[1000001];
int c[1000001];
string op;
int con;

void dfs(int src)
{
    vis[src] = 1;
    c[src] = con;
    for (int nbr : adjlist[src])
    {
        if (vis[nbr] == 0)
        {
            dfs(nbr);
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
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> edglist;
        int n, k;
        con = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            adjlist[i].clear();
            vis[i] = 0;
        }
        int x1, x2;
        for (int i = 1; i <= k; i++)
        {
            cin >> x1 >> op >> x2;
            if (op == "=")
            {
                adjlist[x1].pb(x2);
                adjlist[x2].pb(x1);
            }
            else
            {
                edglist.pb(mp(x1, x2));
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                con++;
                dfs(i);
            }
        }
        bool flag = true;
        int p, q;
        for (int i = 0; i < edglist.size(); i++)
        {
            p = edglist[i].first;
            q = edglist[i].second;
            if (c[p] == c[q])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            yes;
        }
        else
        {
            no;
        }
    }
}

