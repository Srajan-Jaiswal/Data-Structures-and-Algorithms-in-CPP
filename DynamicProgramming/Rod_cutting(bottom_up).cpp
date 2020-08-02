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
int max_profit(int *arr, int ttlen) {
	int prof = 0;
	int dp[1001] = {0};
	for (int i = 1; i <= ttlen; i++) {
		for (int j = 1; j <= i; j++) {
			prof = max(prof, arr[j] + dp[i - j])
		}
		dp[i] = prof;
	}
	return dp[ttlen];
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
		int p[n];
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		cout << max_profit(p, n ) << endl;
	}
	return 0;
}