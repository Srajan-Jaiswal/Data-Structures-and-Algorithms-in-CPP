#include<bits/stdc++.h>
using namespace std;
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

// recursive soln  exponential complexity
int catalan_no_rec(int n)
{
	if (n <= 0) {
		return 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += catalan_no_rec(i - 1) * catalan_no_rec(n - i);
	}
	return ans;
}

// count no of binary search trees using catalan no DP(Bottom UP)
int count_bst(int n) {
	int 	bst[n + 1] = {0};
	bst[0] = 1;
	bst[1] = 1;
	int ans = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < i; j++) {
			bst[i] += bst[j - 1] * bst[i - j];
		}
	}
	return bst[n];
}

// DP (Bottom UP)  O(N2) solution
int catalan_DP(int n) {
	int dp[n + 1] = {0};
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	return dp[n];
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
		cout << catalan_DP(n) << endl;
	}
	return 0;
}
