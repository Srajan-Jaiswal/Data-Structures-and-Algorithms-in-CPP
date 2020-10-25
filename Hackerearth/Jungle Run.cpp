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

int n;
char arr[31][31];
bool vis[31][31];
int dis[31][31];

bool valid(int x, int y)
{
	if(x<1 || x>n || y<1 || y>n || arr[x][y] == 'T')
	{
		return false;
	}
	else if(vis[x][y])
	{
		return false;
	}
    else{
		return true;
	}
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void BFS(int sx , int sy)
{
	queue<pair<int, int>> q;
	q.push(mp(sx,sy));
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	while(!q.empty())
	{
		pair<int,int> p_curr = q.front();
		q.pop();
		for(int i=1;i<=4;i++)
		{
			if(valid(p_curr.ff+dx[i],p_curr.ss+dy[i]))
			{
				pair<int,int> p_new = mp(p_curr.ff+dx[i],p_curr.ss+dy[i]);
				vis[p_new.ff][p_new.ss]=1;
				dis[p_new.ff][p_new.ss] = dis[p_curr.ff][p_curr.ss] + 1;
				q.push(p_new);
			}
		}

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
	   cin>>n;
	   int Sx,Sy,Ex,Ey;
       fre(i,1,n)
	   {
		   fre(j,1,n)
		   {
			   cin>>arr[i][j];
			   if(arr[i][j]=='S')
			  {
				  Sx=i;
				  Sy=j;	  
			  }
			  else if(arr[i][j]=='E'){
                 Ex=i;
				 Ey=j;
			  }
		   }
	   }
	   BFS(Sx,Sy);
	   cout<<dis[Ex][Ey]<<endl;
}
