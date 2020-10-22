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


bool vis[1001][1001];

bool valid(int x, int y, int n, int m)
{
    if(x<1 || x>n || y<1 || y>m)
    {
        return false;
    }
    if(vis[x][y] == true)
    {
        return false;
    } 
    else{
        return true;
    }
}

void DFS(int x, int y, int n ,int m)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;
    if(valid(x-1,y,n,m))
    {
        DFS(x-1,y,n,m);
    }
    if(valid(x,y+1,n,m))
    {
        DFS(x,y+1,n,m);
    }
    if(valid(x+1,y,n,m))
    {
        DFS(x+1,y,n,m);
    }
    if(valid(x,y-1,n,m))
    {
        DFS(x,y-1,n,m);
    }
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
	cin >> t;
	while (t--)
	{
        int n,m;
        cin>>n>>m;
        DFS(1,1,n,m);
    }
}
