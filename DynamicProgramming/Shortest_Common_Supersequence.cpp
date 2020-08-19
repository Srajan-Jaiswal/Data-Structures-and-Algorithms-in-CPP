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
int static dp[1001][1001];
int LCS(string a, string b, int n, int m)
{
	if (m == 0 || n == 0) {
		return 0;
	}
	if (dp[n - 1][m - 1] != 0)
	{
		return dp[n - 1][m - 1];
	}
	if (a[n - 1] == b[m - 1])
	{
		dp[n - 1][m - 1] = 1 + LCS(a, b, n - 1, m - 1);
	}
	else {
		dp[n - 1][m - 1] = max((LCS(a, b, n, m - 1)), (LCS(a, b, n - 1, m)));
	}
	return dp[n - 1][m - 1];
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
		string s;
		string p;
		cin >> s >> p;
		memset(dp , 0, sizeof(dp));
		string q = s + p;
		int ans = q.length();
		int res = ans - LCS(s, p, n, m);
		cout << ans << endl;
	}
	return 0;
}