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
void subseq(string str)
{
	set<string> se;
	fr(i, str.length()) {
		for (int j = str.length(); j >= 0; j--) {
			string s_s = str.substr(i, j);
			se.insert(s_s);
			for (int k = 0; k < s_s.length(); k++) {
				string ans = s_s;
				ans.erase(ans.begin() + k);
				subseq(ans);
			}
		}
	}
	for (auto it : se) {
		cout << it << endl;
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
		string s;
		cin >> s;
		subseq(s);
	}
	return 0;
}