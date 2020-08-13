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

// Recursive Approach
bool eq_part(vector<int> &v, int sum, int n)
{
	if (sum == 0)
	{
		return  true;
	}
	if (n == 0 && sum != 0)
	{
		return false;
	}
	if (v[n - 1] <= sum)
	{
		return eq_part(v, sum - v[n - 1], n - 1) ||  eq_part(v, sum, n - 1);
	}
	else
	{
		return eq_part(v, sum, n - 1);
	}
}
bool eq_part_util(vector<int> &v, int n)
{
	int sum = 0;
	for (auto i : v)
	{
		sum += i;
	}
	if (sum % 2 != 0)
	{
		return false;
	}
	else
	{
		sum = sum / 2;
		return eq_part(v, sum, n);
	}
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int input;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			v.push_back(input);
		}
		if (eq_part_util)
		{
			cout << "T" << endl;
		}
		else {
			cout << "F" << endl;
		}
	}
	return 0;
}
