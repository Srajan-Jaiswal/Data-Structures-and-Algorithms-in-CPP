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
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, l;
		cin >> n >> k >> l;
		int cnt = 0;
        if(n%l==0 && n/l > k)
        {
			cout << -1;
        }
        else if(n%l==1 && (n/l+1) > k)
        {
			cout << -1;
        }

		else
		{
			int i = 1;
			bool flag = 0;
			int res = 0;
			while (i <= k)
			{
				while (cnt < l && res < n)
				{
					if (k % 2 == 0)
					{
						if (res <= n - 2)
						{
							cout <<" "<< i << " " << i + 1;
							cnt++;
							res += 2;
						}
						else
						{
							cout << " " << i;
							res += 1;
						}
					}

					else
					{
						if (flag == 0 && res <= n - 3)
						{ // k==5
							cout <<" "<< i << " " << i + 1 << " " << k;
							cnt++;
							res += 3;
						}
						else if(flag==1 && res <= n - 2)
						{
							cout <<" "<<i << " " << i + 1;
							cnt++;
							res = res + 2;
						}
						else
						{
							cout <<" "<<i;
							cnt++;
							res = res + 1;
						}
					}
				}
				flag = 1;
				i = i + 2;
				cnt = 0;
			}
		}
	  cout<<endl;
    }
}
