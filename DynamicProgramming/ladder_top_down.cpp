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
int ladder(int n, int k, int *dp) {
	if (n == 0) {
		return 1;
	}
	if (dp[n] != 0) {
		return  dp[n];
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		if (n - i >= 0) {
			ans += ladder(n - i, k, dp);
		}
	}
	return dp[n] = ans;
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
		int n, k;
		cin >> n >> k;
		int dp[n] = {0};
		cout << ladder(n, k) << endl;
	}
	return 0;
}