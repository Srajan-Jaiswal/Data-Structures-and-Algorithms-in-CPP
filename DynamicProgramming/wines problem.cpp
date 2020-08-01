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
int  profit(int *arr, int i, int j, int y, int dp[][1001])
{
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != 0) {
		return dp[i][j];
	}
	int op1 = (arr[i] * y + profit(arr, i + 1, j, y + 1, dp));
	int op2 = (arr[j] * y + profit(arr, i, j - 1, y + 1, dp));
	return dp[i][j] =  max(op1, op2);
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
		int arr[n];
		int dp[1001][1001] = {0};
		fr(i, n) {
			cin >> arr[i];
		}
		int y = 1;
		cout << profit(arr, 0, n - 1, y, dp) << endl;
	}
	return 0;
}