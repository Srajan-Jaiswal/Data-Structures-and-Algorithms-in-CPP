class Solution
{
    public:
    bool flag = false;
    bool check_path(vector <vector <int>> &grid,int x,int y,vector <vector <bool>>& vis,int n){
         if(x>=n || x<0 || y>=n || y<0|| vis[x][y]==true || grid[x][y]==0) return false;
         return true;
    }
    void dfs(vector <vector <int>> &grid,int x,int y,int  dest_x,int dest_y,vector <vector <bool>>& vis,int n){
    if(!check_path(grid,x,y,vis,n)) return;
    vis[x][y]=true;
    if(x==dest_x && y== dest_y){
        flag = true;
        return;
    }
    dfs(grid,x+1,y,dest_x,dest_y,vis,n);
    dfs(grid,x-1,y,dest_x,dest_y,vis,n);
    dfs(grid,x,y+1,dest_x,dest_y,vis,n);
    dfs(grid,x,y-1,dest_x,dest_y,vis,n);
}
bool is_Possible(vector<vector<int>> &grid) {
    int  n = grid.size();
    vector <vector <bool>> vis(n,vector <bool>(n,false));
    int src_x,src_y,dest_x,dest_y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                src_x=i;
                src_y=j;
            }
            else if(grid[i][j]==2){
                dest_x = i;
                dest_y = j;
            }
        }
    }
    dfs(grid,src_x,src_y,dest_x,dest_y,vis,n);
    return flag;
}
    
    
    
    
};
