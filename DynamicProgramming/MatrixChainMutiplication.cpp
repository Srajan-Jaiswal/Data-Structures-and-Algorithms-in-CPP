#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr0(i,n)  for(int i=0;i<n;i++)
#define fr1(i,n)  for(int i=1;i<n;i++)
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


// recursive soln O(exponential)
int MCM_Rec(vector<int> &v, int r, int c)
{
	if (r == c) { // base
		return 0;
	}
	int k, cnt;
	int comp = INT_MAX;
	for (p = r; p < c; p++)  // pivot
	{
		cnt = MCM_Rec(v, r, p) +
		      MCM_Rec(v, p + 1, c) +
		      v[r - 1] * v[p] * v[c];

		if (cnt < comp)
			comp = cnt;
	}
	return comp;
}


// optimisation  using memorisation(top down)   complexity O(n3)
int MCM(vector<int> &v) {
	int dp[1001][1001];
	memset(dp, 0, sizeof dp);
	int n = v.size() - 1;
	fr1(i, n) {
		int r = 0, c = i; // moving diagonally to fill dp
		while (c < n) {
			int comp = INT_MAX;
			for (int p = r; p < c; p++) { // pivot
				comp = min(comp, dp[r][p] + dp[p + 1][c] + (v[r] * v[p + 1] * v[c + 1]));

			}
			dp[r][c] = comp;
			r++;
			c++;
		}
	}
	return dp[0][n - 1];
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
		int input;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			v.push_back(input);
		}
		// cout<< MCM_Rec(v,1,n-1)<<endl;
		cout << MCM(v) << endl;
	}
	return 0;
}