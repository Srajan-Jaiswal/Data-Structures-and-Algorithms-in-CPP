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


vector<int> *arr = new vector<int>[100001];
vector<int> vis;
void dfs(int node)
{
	vis[node] = 1;
	for (int nbr : arr[node])
	{
		if (!vis[nbr])
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

	int n, e;
	cin >> n >> e;
	int ans = 0;
	for (int i = 1; i <= e; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	for (int i = 1; i <= n; i++)
	{
		vis.pb(0);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans << endl;
}
