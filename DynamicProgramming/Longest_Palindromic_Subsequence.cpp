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
string LCS(string a, string b, int n, int m)
{
	string ans = " ";
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	int i = m;
	int j = n ;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--;
			j--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--;
			else
				i--;
		}
	}
	reverse(ans.begin(), ans.end());
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
		string s;
		cin >> s;
		int n = s.length();
		string p = " ";
		p = s;
		reverse(p.begin(), p.end());
		int m = p.length();
		string z = LCS(s, p, n, m);
		for (int i = 0; i < z.length(); i++)
		{
			cout << z[i];
		}
		cout << endl;
	}
	return 0;
}