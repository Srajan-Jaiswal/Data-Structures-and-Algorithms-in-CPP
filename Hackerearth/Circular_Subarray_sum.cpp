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
int kadane(int a[], int n);

int maxCircularSum(int *a, int n)
{
int max_kadane = kadane(a, n);
int cir = 0, i;
fr (i,0,n)
{
        cir += a[i];     
        a[i] = -a[i];       
}

cir = cir + kadane(a, n);
return (cir > max_kadane)? cir: max_kadane;
}
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    fr (i,0,n)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
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
    cin>>t;
    fr (i,0,t)
    {
       int n;
       cin>>n;
       int a[n];
       fr (j,0,n)
       {
           cin>>a[j];
       }
        cout<< maxCircularSum(a, n) <<endl;
    }
    return 0;
}
