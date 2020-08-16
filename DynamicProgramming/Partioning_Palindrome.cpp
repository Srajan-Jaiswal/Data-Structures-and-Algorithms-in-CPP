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

bool is_palin(string s, int a, int b)
{
	while (a < b)
	{
		if (s[a] == s[b]) {
			a++;
			b--;
		}
		else {
			return false;
			break;
		}
	}
	return true;
}

// Recursion 
int part_palindrome_rec(string str, int i, int j)
{
	if (i >= j)
	{
		return 0;
	}
	if (is_palin(str, i, j))
	{
		return 0;
	}
	int ans = INT_MAX;
	for (int k = i; k < j; k++)
	{
		ans = min(ans , part_palindrome_rec(str, i, k) + part_palindrome_rec(str, k + 1, j) + 1);
	}
	return ans;
}
int static dp[1001][1001];
//  optimised memorisation  O(n2)
int part_palindrome_rec(string str, int i, int j)
{
	if (i >= j)
	{
		return 0;
	}
	if (is_palin(str, i, j))
	{
		return 0;
	}
	int ans = INT_MAX;
	int l, r;
	for (int k = i; k < j; k++)
	{
		if (dp[i][k] != 0) {
			l = dp[i][k];
		}
		else {
			l = part_palindrome_rec(str, i, k);
			dp[i][k] = l;
		}
		if (dp[k + 1][j] != 0) {
			r = dp[k + 1][j];
		}
		else {
			r = part_palindrome_rec(str, k + 1, j);
			dp[k + 1][j] = r;
		}
		ans = min(ans , (l + r + 1));
	}
	return ans;
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
		string str;
		cin >> str;
		memset(dp,0 ,sizeof dp);
		int n = str.length();
		cout << part_palindrome_rec(str, 0, n - 1) << endl;		
	}
	return 0;
}

