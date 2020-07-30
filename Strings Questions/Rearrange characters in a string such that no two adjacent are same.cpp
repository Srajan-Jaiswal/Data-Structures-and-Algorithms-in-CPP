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


void comp(const pair<char, int> &a, const pair<char, int> &b)
{
	return (a.second > b.second);
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
		unordered_map<char, int> m;
		for (int i = 0; i < s.length(); i++)
		{
			m[s[i]]++;
		}
		vector<pair<char, int>> v;
		for (auto it : m)
		{
			v.push_back(make_pair(it.first, it.second));
		}
		sort(v.begin(), v.end(), comp);

		while (!v.empty())
		{
			for (auto it : v)
			{
				pair<char, int> p = it;
				if (it.second != 0)
				{
					cout << it.first << " ";
					it.second--;
				}
				else {
					v.erase(it);
				}
			}
		}

	}
	return 0;
}