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
int precedence(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	else if (ch == '^')
	{
		return 3;
	}
	else {
		return 0;
	}
}
string InfixToPostfix(string infix)
{
	stack<char> stk;
	stk.push('#');
	string postfix = " ";
	string::iterator it;

	for (it = infix.begin(); it != infix.end(); it++)
	{
		if ((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z')) // add character directly to the postfix
		{
			postfix += *it;
		}
		else if (*it == '(')
		{
			stk.push('(');
		}
		else if ( *it == '^')
		{
			stk.push('^');
		}
		else if (*it == ')')
		{
			while (stk.top() != '#' &&  stk.top() != '(')
			{	//  while loop actually checks that either the top element has  ')'  or it should be #
				//  stk.top() updates and pop all eleents
				postfix += stk.top();
				stk.pop();
			}
			stk.pop(); // remove ( from the  stack
		}
		else
		{
			if (precedence(*it) > precedence(stk.top()) )
				stk.push(*it);    // push  if the precedence is high
			else
			{
				while (stk.top() != '#' && precedence(*it) <= precedence(stk.top()))
				{
					postfix += stk.top();  // remember that this line only means that top of the stack is updated
					stk.pop();
				}
				stk.push(*it);
			}
		}
	}

	while (stk.top() != '#')
	{	// store and pop until the stack not empty
		postfix += stk.top();
		stk.pop();
	}

	return postfix;
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

		string infix = "x^y/(5*z)+2";
		cout << " postfix form is :" << InfixToPostfix(infix) << endl;
	}
	return 0;
}