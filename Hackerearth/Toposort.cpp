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
int indeg[100001];
vector<int> ans;

bool toposort(int n)
{
	priority_queue<int ,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
			pq.push(i);
		}
	}
	while(!pq.empty())
	{
		int node = pq.top();
		ans.push_back(node);
		pq.pop();
		for(int nbr: arr[node])
		{
			indeg[nbr]--;
		    if(indeg[nbr] == 0)
			{
				pq.push(nbr);
			}
		}
	}
    if(ans.size() == n)
	{
		return true;
	}
	else{
		return false;
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
	   for(int i=1;i<=n;i++)
	   {
		   arr[i].clear();
		   indeg[i]=0;
	   }
	   for(int i=1;i<=m;i++)
	   {
		   int u,v;
		   cin>>u>>v;
		   arr[u].push_back(v);
		   indeg[v]++;
	   }	
	   if(!toposort(n)){
		   cout<<"Sandro fails."<<endl;
	   }
	   else
	   {
		   for(auto it : ans)
		   {
			   cout<<it<<" ";
		   }
	   }
	   
	   cout<<endl;
	}
}
