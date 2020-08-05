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