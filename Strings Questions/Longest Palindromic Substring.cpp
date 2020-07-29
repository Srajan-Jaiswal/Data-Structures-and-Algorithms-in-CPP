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
void print(string str, int l, int h)
{
	for (int i = l; i <= h; ++i)
		cout << str[i];
}
void lps(string str)
{
	int idx = 0;
	int max_len = 1;

	fr(i, str.length())
	{
		fr(j, str.length())
		{
			fr(k, (j - i + 1 ) / 2)
			{
				bool i_t = true;
				if (str[i + k] != str[j - k])
				{
					i_t = false;
				}
				if (i_t && (j - i + 1) > max_len)
				{
					idx = i;
					max_len = j - i + 1;
				}
			}
		}
	}
	print(str, idx, idx + max_len - 1);
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
		string str;
		cin >> str;
		lps(str);
	}
	return 0;
}