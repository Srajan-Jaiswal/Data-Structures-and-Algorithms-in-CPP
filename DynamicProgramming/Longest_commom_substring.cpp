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
int lcs_substr(string s, string p, int n, int m)
{
	int res = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (s[i - 1] == p[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	return res;
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
		cout << lcs_substr(s, p, n, m) << endl;
	}
	return 0;
}