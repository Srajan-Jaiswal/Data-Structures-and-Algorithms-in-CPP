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
int max_sum(int* arr, int n)
{
	int dp[10001] = {0};
	dp[0] = arr[0] > 0 ? arr[0] : 0;
	int max_till = dp[0];
	fr(i, n) {
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] < 0) {
			dp[i] = 0;
		}
		max_till = max(max_till, dp[i]);
	}
	return max_till;
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
		int a[n];
		fr(i, n) {
			cin >> c[i];
		}

		cout << max_sum(a, n) << endl;
	}
	return 0;
}
