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
int LCS(string str1, string str2, a, b) {
	int dp[10001][10001];
	for (int i = 0; i <= a; i++) {
		dp[i][0] = {0};
	}
	for (int j = 0; j <= b; j++) {
		dp[0][j] = {0};
	}

	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++) {
			int ans = 0;
			if (str1[i - 1] == str2[j - 1]) {
				ans = 1 + dp[i - 1][j - 1];
			}
			else {
				ans = max(dp[i - 1][j], dp[i][j - 1])
			}
			dp[i][j] = ans;
		}
	}
	return dp[a][b];
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
		string str1;
		string str2;
		cin >> str1 >> str2;
		int m = str1.length();
		int n = str2.length();
		cout << LCS(str1, str2, m, n) << endl;
	}
	return 0;
}
