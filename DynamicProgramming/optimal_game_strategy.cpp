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
int op_game(vector<int> &v, int n)
{
	int dp[1001][1001];
	memset(dp, 0, sizeof dp);
	for (int c = 1; c < n; c++)
	{
		int i = 0 ;
		int j = c;
		while (i < n && j < n)
		{
			if (i == j)
			{
				dp[i][j] = 0;
			}
			dp[i][j] = max((v[i] + min(dp[i + 2][j], dp[i + 1][j - 1])) , v[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
			i++, j++;
		}
	}
	return dp[0][n - 1];
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
		vector<int> v;
		int n, p;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> p;
			v.pb(p);
		}
		cout << op_game(v, n) << endl;
	}
	return 0;
}

