// Top down

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,n)  for(int i=0;i<n;i++)
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
int Min_change(int *c, int n, int T, int *dp)
{
	if (n == 0)
	{
		return 0;
	}
	int ans = INT_MAX;
	if (dp[n] != 0) {
		return dp[n];
	}
	for (int i = 0; i <= T; i++)
	{
		if (n - c[i] >= 0)
		{
			int sub = Min_change(c, n - c[i], T, dp)
			          ans = min(ans, sub + 1);
		}
	}
	dp[n] = ans;
	return dp[n];
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
		int n;
		cin >> n;
		int T;
		cin >> T;
		int c[n];
		fr(i, T) {
			cin >> c[i];
		}
		int dp[] = {0};
		cout << Min_change(c, n, T, dp) << endl;
	}
	return 0;
}