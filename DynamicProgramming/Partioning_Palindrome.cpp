/* Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1*/
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
		int n = str.length();
		cout << part_palindrome_rec(str, 0, n - 1) << endl;
	}
	return 0;
}

