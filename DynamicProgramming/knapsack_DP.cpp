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
// recursive case in  knapsack  Complexity O(2^n)
int knapsack_rec(vector<int> &wt, vector<int> &vl, int w, int n) {
	if (n == 0 || w == 0) {
		return 0;
	}
	if (wt[n - 1] <= w) {
		return max(vl[n - 1] + knapsack_rec(wt, vl, w - wt[n - 1], n - 1), knapsack_rec(wt, vl, w, n - 1));
	}
	else {
		return knapsack_rec(wt, vl, w, n - 1);
	}
}
//optimised O(n*w)
int knapsack_TD(vector<int> &wt, vector<int> &vl, int w, int n) {
	dp[n + 1][wt + 1];
	mem(dp, -1);
	if (n == 0 || w == 0) {
		return 0;
	}
	if (dp[n][w] != -1)
	{
		return dp[n][w];
	}
	if (wt[n - 1] <= w) {
		return dp[n][w] = max(vl[n - 1] + knapsack_rec(wt, vl, w - wt[n - 1], n - 1), knapsack_rec(wt, vl, w, n - 1));
	}
	else {
		return dp[n][w] = knapsack_rec(wt, vl, w, n - 1);
	}
	return dp[n][w] = knapsack_rec(wt, vl, w, n - 1);
}
// T Complexity O(n*w)
int knapsack_BU(vector<int> &wt, vector<int> &vl, int w, int v) {
	dp[n + 1][w + 1];
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < w + 1; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] == 0;
			}
			else if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][m];
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
		int n, wt;
		cin >> n >> wt;
		vector<int> wt;
		vector<int> vl;
		int ipt;
		fr(i, 0, n) {
			cin >> ipt;
			wt.pb(ipt);
		}
		fr(i, 0, n) {
			cin >> ipt;
			wt.pb(ipt);
		}
		cout << knapsack(wt, vl, w, n) << endl;
	}
	return 0;
}
