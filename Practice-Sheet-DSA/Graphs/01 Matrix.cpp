class Solution {
public:
    bool valid(int x,int y,int n,int m){
        if(x>=n || y>=m || x<0 || y<0) return false;
        return true;
    } 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n,vector<int>(m, INT_MAX));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]==0){
                   dis[i][j]=0;
                   q.push(make_pair(i,j));
               }
           }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            int s = q.size();
            for(int k=0;k<s;k++){
            pair<int,int> pr = q.front();
            int old_x = pr.first;
            int old_y = pr.second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_x = old_x + dx[i];
                int new_y = old_y + dy[i];
                if(valid(new_x,new_y,n,m)){
                    if(dis[new_x][new_y] > dis[old_x][old_y] + 1){
                        dis[new_x][new_y] = dis[old_x][old_y] + 1;
                        q.push({new_x,new_y});
                    }
                }   
            }
          }
        }
        return dis;
    }
};
