
int n;
char arr[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];

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

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

void BFS(int sx , int sy)
{
	queue<pair<int, int>> q;
	q.push(mp(sx,sy));
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	while(!q.empty())
	{
		int p_curr_x = q.front().ff;
		int p_curr_y = q.front().ss;
		q.pop();
		for(int i=1;i<=8;i++)
		{
			if(valid(p_curr_x+dx[i],p_curr_y+dy[i]))
			{
			 	int p_curr_new_x=p_curr_x;
				int p_curr_new_y=p_curr_y;
				vis[p_curr_new_x][p_curr_new_y]=1;
				dis[p_curr_new_x][p_curr_new_y] = dis[p_curr_x][p_curr_y] + 1;
				q.push(mp(p_curr_new_x,p_curr_new_y));
			}
		}

	}
} 
