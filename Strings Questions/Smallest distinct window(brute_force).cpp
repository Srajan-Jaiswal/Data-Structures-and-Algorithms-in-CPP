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
		set<char>st;
		string ans;
		int cnt = 0;
		fr(i, s.length()) {
			st.insert(s[i]);
		}
		string sub = " ";
		int comp = INT_MAX;
		int siz = st.size();
		fr(i, s.length()) {
			for (int j = i; j < s.length(); j++) {
				int vis[256] = {0};

				if (vis[s[j]] == 0)
				{
					cnt++;
					vis[s[j]] = 1;
				}
				sub += s[j];
				if (cnt == siz)
					break;
			}
			if (sub.size() < comp &&  cnt == siz)
			{
				comp = sub.size();
				ans = sub;
			}
		}
		cout << ans << endl;
	}
	return 0;
}