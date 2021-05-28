class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0])  DFS(grid, i, 0);
        }
        for(int i = 0; i < grid.size(); i++){ 
            if(grid[i][grid[0].size() - 1]) DFS(grid, i, grid[0].size() - 1);
        }
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[0][i])  DFS(grid, 0, i);
        }
        
        for(int i = 0; i < grid[0].size(); i++){  
            if(grid[grid.size() - 1][i])  DFS(grid, grid.size() - 1, i);
        }
        
        for(int i = 1; i < grid.size() - 1; i++){
            for(int j = 1; j < grid[0].size() - 1; j++){
                if(grid[i][j]) ans++;
            }
        }
        return ans;
    }
};
