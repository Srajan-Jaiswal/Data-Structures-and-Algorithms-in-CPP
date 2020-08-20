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
string LCS(string s , string p, int n, int  m)
{	int i, j;
	for ( i = 0; i <= n; i++) {
		for ( j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (s[i - 1] == p[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int idx = dp[n][m];
	string ans = " ";
	while (i > 0 || j > 0)
	{

		if (s[i - 1] == p[j - 1])
		{
			ans.push_back(s[i - 1]);
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else {
			j--;
		}
	}
	return ans;
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
		string z = LCS(s, p, n, m);
		reverse(z.begin(), z.end());
		unordered_map<char, int> mp;
		for (int i = 0; i < s.length(); i++)
		{
			mp[s[i]]++;
		}
		for (int i = 0; i < z.length(); i++)
		{
			mp[z[i]]--;
		}
		for (auto it : mp)
		{
			cout << it.first << " ";
		}
		//int ans = s.length() - LCS(s, p, n, m)
		//        cout << ans << endl;
	}
	return 0;
}