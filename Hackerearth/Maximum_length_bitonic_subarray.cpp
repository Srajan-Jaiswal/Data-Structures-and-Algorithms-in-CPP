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
int bitonic(int arr[], int n)
{
    int inc[n]; 
    int dec[n]; 
    int i, max;
    inc[0] = 1;
    dec[n-1] = 1;
    for (i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i-1])
        {
            inc[i] = inc[i-1]+1;
        }
        else{
            inc[i]=1;
        }
    }
    for (i = n-2; i >= 0; i--)
    {
        if(arr[i] >= arr[i+1])
        {
            dec[i]=dec[i+1]+1;
        }
        else{
            dec[i]=1;
        }
    }
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++){
        if (inc[i] + dec[i] - 1 > max){
            max = inc[i] + dec[i] - 1;
        }
    }
    return max;
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
        cout<< bitonic(a, n) <<endl;
    }
    return 0;
}
