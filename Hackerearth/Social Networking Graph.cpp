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

vector<int> arr[100001];
int vis[100001];
int dis[100001];
int level[100001];
int BFS(int src,int t)
{
    queue<int> q;
	q.push(src);
	vis[src] = 1;
	dis[src]=0;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(int nbr : arr[node])
		{
			if(vis[nbr] != 1)
			{
				q.push(nbr);
				dis[nbr] = dis[node]+1;
				vis[nbr]=1;
				level[dis[nbr]]++;
			}
		}

	}
	return level[t];
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
	
	int n,e;
    cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		 int u,v;
		 cin>>u>>v;
	     arr[u].push_back(v);
		 arr[v].push_back(u);
	}	
	int m;
	cin>>m;
	while(m--)
	{
		int src,t;
		cin>>src>>t;
		for(int i=0;i<=n;i++)
		{
			vis[i]=0;
			level[i]=0;
		}
		cout<<BFS(src,t);
        cout<<endl;	
	}	
}


