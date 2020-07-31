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
bool isip(string s) {
	int n = s.length();
	string k = "";
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.')
		{
			flag = 0;
			if (k.length() > 1 && k[0] == '0')
			{
				return 0;
			}
			if (k.length() > 3 || k.length() < 1 || stoi(k) < 0 || stoi(k) > 255)
			{
				return 0;
			}
			k = "";
		}
		else {
			k += s[i];
		}
	}
	if (k.length() > 1 && k[0] == '0')
	{
		return 0;
	}
	if (k.length() > 3 || k.length() < 1 || stoi(k) < 0 || stoi(k) > 255)
	{
		return 0;
	}
	return 1;
}
vector<string> restoreIpAddresses(string A) {
	int l = A.length();
	vector<string> v;
	string s = A;
	for (int i = 0; i < l - 2; i++) {
		for (int j = i + 1; j < l - 1; j++) {
			for (int k = j + 1; k < l; k++) {
				s = s.substr(0, k) + "." + s.substr(k);
				s = s.substr(0, j) + "." + s.substr(j);
				s = s.substr(0, i) + "." + s.substr(i);
				if (isip(s))
					v.push_back(s);
				s = A;
			}
		}
	}
	return v;
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
		vector<string> v = restoreIpAddresses(s);
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;

	}
	return 0;
}