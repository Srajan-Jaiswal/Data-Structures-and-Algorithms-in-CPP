// o(n2)

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
		string s;
		cin >> s;
		int res = 0;
		for (int i = 0; i < s.length(); i++)
		{	int  arr[26] = {0};
			for (int j = 0; j < s.length()) {
				arr[s[j] - 'a']++;
				if (arr[s[j] - 'a'] > k)
				{
					break;
				}

				fr(i, 26) {
					if (arr[i] > 0 & arr[i] != k) {
						cout << "0" << endl;
					}
					else {
						res++;
					}
				}

			}
		}
		cout << res << endl;

	}
	return 0;
}