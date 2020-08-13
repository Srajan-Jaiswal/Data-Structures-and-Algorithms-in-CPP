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
int cnt_subset(vector<int> &v, int sum, int n, int cnt)
{
  if (n == 0)
  {
    cnt += 1;
    return cnt ;
  }
  if (n == 0 && sum != 0)
  {
    return cnt;
  }
  if (v[n - 1] <= sum)
  {
    return cnt_subset(v, sum - v[n - 1], n - 1, cnt) || cnt_subset(v, sum, n - 1, cnt);
  }
  else
  {
    return cnt_subset(v, sum, n - 1, cnt);
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
  int ans;
  while (t--)
  {
    int n, inp, sum;
    vector<int> vec;
    cin >> n >> sum;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> inp;
      vec.pb(inp);
    }
    cout << cnt_subset(vec, sum, n, cnt);
  }
  return 0;
}
