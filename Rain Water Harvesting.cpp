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
int a[1000000], l[1000000], r[1000000];
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    l[0] = a[0];
    r[n - 1] = a[n - 1];
    int leftmax = 0, rightmax = 0;
    for (i = 1; i < n; i++)
    {
        l[i] = max(l[i - 1], a[i]);
    }
    for (i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], a[i]);
    }
    int water = 0;
    for (i = 0; i < n; i++)
    {
        water += (min(l[i], r[i]) - a[i]);
    }
    cout << water;

    return 0;
}
