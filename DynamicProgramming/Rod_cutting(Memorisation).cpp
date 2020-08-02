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
int cut_rod(int *arr, int n)
{
	int dp[n] = {0};
	if (n == 0) {
		return  0;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	int ans;
	int pro = 0;
	fr(i, n) {
		ans = arr[i] + cut_rod(arr, n - i);
		pro = max(pro, ans);
	}
	return dp[n] = pro;
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
		fr(i, n) {
			cin >> p[i];
		}
		cout << cut_rod(p, n ) << endl;
	}
	return 0;
}