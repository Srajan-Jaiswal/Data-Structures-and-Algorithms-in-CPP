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
int find_operator(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	else
	{
		return 0;
	}
}
string Prefix_To_Infix( string prefix)
{
	stack<string> stk;

	string::iterator it ;
	for (it = prefix.end(); it != prefix.begin() ; it-- )
	{
		if (find_operator(*it))   // if we have find an operator the we have to pop firstly two elements from stack
		{
			string op1 = stk.top();  stk.pop();
			string  op2 = stk.top();  stk.pop();
			string temp = "(" + op1 + find_operator(*it) + op2 + ")" ;
			stk.push(temp);
		}
		else
		{
			stk.push(string(1, *it));
		}
	}
	return s.top();
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

		string prefix = "-a/bc-/akl";
		cout << "INFIX :" << Prefix_To_Infix(prefix);
	}
	return 0;
}