#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, n) for (int i = a; i < n; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
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
string compress(string s)
{
    if (s.size() == 0)
    {
        return "";
    }

    char ch = s[0];
    int i = 1;
    while (i < s.size() && s[i] == ch)
    {
        i++;
    }
    string ros = s.substr(i);
    ros = compress(ros);
    string charCount = to_string(i);
    return ch + charCount + ros;
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
	string s;
    cin >> s;
    cout << compress(s) << endl;
    return 0;
}
