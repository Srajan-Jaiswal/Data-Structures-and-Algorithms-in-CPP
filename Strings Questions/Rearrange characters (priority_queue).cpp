/*Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.*/


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
		string s1 = " ";
		priority_queue<pair<int, char>> pq;
		int arr[26] = {0};
		fr(i, s.length()) {
			arr[str[i] - 'a']++;
		}
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (arr[i - 'a'])
			{
				pq.push(mp(arr[i - 'a']));
			}
		}
		pair<int, char> old = mp(-1, #);
		while (!pq.empty())
		{
			pair<int, char> p = pq.top();
			pq.pop();
			s1 += p.second;

			if (old.first > 0)
			{
				pq.push(old);
			}
			(p.first)--;
			old = p;
		}
		if (s1 != str.length()) {
			cout << "0" << endl;
		}
		else {
			cout << str << endl;
		}
	}
	return 0;
}
