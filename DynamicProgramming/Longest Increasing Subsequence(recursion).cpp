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
int LIS(int *arr, int n, int *ans)   // recursion  solution LIS  O(exponential)
{
	if (n == 1) {
		return 1;
	}
	int res, answ = 1;
	for (int i = 1; i < n; i++) {
		res = LIS(arr, n, ans);
		if (arr[i - 1] <= arr[n - 1] && res + 1 > answ) {
			answ = 1 + res;
		}
	}
	if (*ans < answ) {
		*ans = answ;
	}
	return answ;
}
void LIS_util(int *arr, int n) {
	int *lis = 1;
	LIS(arr, n, &lis);
	return lis;
}

//  DP (Bottom UP) solution  
int LIS_DP(int *arr, int n) {        
	int dp[n + 1];
	dp[0] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
	}
	
	
	//  O(N2) Complexity
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[j] < arr[i] && arr[i] < dp[j + 1]) {
				dp[j + 1] = arr[i];
			}
		}
		
		
		// binary  Search optimisation O(N2)-->nlogn complexity
		for (int i = 0; i < n; i++) {
		int idx = upper_bound(dp, dp + n + 1, arr[i])-dp;
		if(dp[idx-1]<arr[i] && dp[idx]>arr[i]){
			dp[idx]=arr[i];
		}
	}
		
		
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INT_MAX) {
			ans = i;
		}
	}
	// Length of LIS 
	return ans;
	
	// For printing LIS
	for (int i = 1; i <= n; i++) {    
		if (dp[i] != INT_MAX) {
			cout<<dp[i];
		}
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
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		fr(i, n) {
			cin >> arr[i];
		}
		cout << LIS_util(arr, n) << endl;
	}
	return 0;
}
