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

int static dp[1001][1001][2];
// optimsed using memorisation 
int bool_parenthesis(string str, int i, int j, bool checkt)
{
	if (i > j) {
		return dp[i][j][checkt] = 0;
	}
	if (i == j) {
		if (checkt)
			return str[i] == 'T' ? dp[i][j][checkt] = 1 : dp[i][j][checkt] = 0;
	}
	else {
		return str[i] == 'F' ? dp[i][j][checkt] = 1 : dp[i][j][checkt] = 0;
	}
	if (dp[i][j][checkt] != -1)
	{
		return dp[i][j][checkt];
	}
	int ans;
	for (int k = i + 1; k <= j - 1; K + 2) {
		// LT
		if (dp[i][k - 1][true] != -1)
		{
			LT = dp[i][k - 1][true];
		}
		else
		{
			LT = bool_parenthesis(str, i, k - 1, true);
			dp[i][k - 1][true] = LT;
		}
		// LF
		if (dp[i][k - 1][false] != -1)
		{
			LF = dp[i][k - 1][false];
		}
		else
		{
			LF = bool_parenthesis(str, i, k - 1, false);
			dp[i][k - 1][false] = LF;
		}
		// RT
		if (dp[k + 1][j][true] != -1)
		{
			RT = dp[k + 1][j][true];
		}
		else
		{
			RT = bool_parenthesis(str, k + 1, j , true);
			dp[k + 1][j][true] = RT;
		}
		//RF
		if (dp[k + 1][j][false] != -1)
		{
			RF = dp[k + 1][j][false];
		}
		else
		{
			RF = bool_parenthesis(str, k + 1, j, false);
			dp[k + 1][j][false] = RF;
		}
		// finding ans for each s[k]
		if (s[k] == '&')
		{
			if (checkt) {
				ans = LT * RT;
			}
			else {
				ans += RT * LF + RF * LT + RF * LF;
			}
		}
		if (s[k] == '|')
		{
			if (checkt) {
				ans += RT * LT + RT * LF + RF * LT;
			}
			else {
				ans += LF * RF;
			}
		}
		if (s[k] == '^')
		{
			if (checkt)
			{
				ans += RF * LT + RT * LF;
			}
			else {
				ans += LF * RF  + LT * RT;
			}
		}
	}
	return dp[i][j][checkt] = ans;
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
		string str;
		cin >> str;
		int n = str.length();
		memset(dp, -1, sizeOf(dp));
		cout << bool_parenthesis(str, 0, n - 1, true) << endl;
	}
	return 0;
}

