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

int dp[2002][2002][6];
int s1[2002],s2[2002];
int k_ordered_LCS(int n, int m, int k){
	int &ans = dp[n][m][k];
	if(ans != 0){
		return ans;
    }
	ans = 0;
	if(n == 0 || m == 0){
		return ans;
    }
	ans = max(k_ordered_LCS(n, m - 1, k), k_ordered_LCS(n - 1, m, k));
	if(s1[n] == s2[m]){
		ans = max(ans, k_ordered_LCS(n - 1, m - 1, k) + 1);
    }
    if(k)
    {
		ans = max(ans, k_ordered_LCS(n - 1, m - 1, k - 1) + 1);
    }
    return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i];
    }
     for(int i=1;i<=m;i++)
    {
        cin>>s2[i];
    }
    memset(dp,0,sizeof(dp));
    cout<<k_ordered_LCS(n,m,k)<<endl;
}
