#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,n)  for(int i=a;i<n;i++)
#define fre(i,a,b)  for(int i=a;i<=b;i++)
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
int dp[1000][1000];
int a[1000];
int sum(int m, int n)
{
	int res = 0;
	for (int i = m; i <= n; i++)
	{
		res += a[i];
		res = res % 100;
	}
	return res;
}
int mixtures(int i, int j)
{
	if (i >= j)
	{
		return 0;
	}
	if (dp[i][j] != 0)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = 0; k <= j; k++)
	{
		dp[i][j] = min(dp[i][j], mixtures(i, k) + mixtures(k + 1, j) + sum(i, k) * sum(k + 1, j));
	}
	return dp[i][j];
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin)   ;
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				dp[i][j] = -1;
			}
		}
		cout << mixtures(0, n - 1) << endl;
	}
	return 0;
}

