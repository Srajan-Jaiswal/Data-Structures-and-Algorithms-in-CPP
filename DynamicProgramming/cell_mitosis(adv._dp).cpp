#include<bits/stdc++.h>
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
using namespace std;
int cell_mitosis(int n, int a, int b, int c)
{
	int * dp = new int[n + 1];
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i < n + 1; i++)
	{
		if (i % 2 == 0)
		{
			return min(dp[i / 2] + a, dp[i - 1] + b);
		}
		else
			return min(dp[i - 1] + b, dp[i + 1 / 2 + a + c]);
	}
	return  dp[n];
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
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		cout << cell_mitosis(n, a, b, c) << endl;
	}
	return 0;
}