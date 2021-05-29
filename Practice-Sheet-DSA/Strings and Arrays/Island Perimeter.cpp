class Solution {
public:
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return true;
        } 
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==0){
            return true;
        }
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                     if(valid(grid,i-1,j)) cnt+=1;
                     if(valid(grid,i,j-1)) cnt+=1;
                     if(valid(grid,i+1,j)) cnt+=1;
                     if(valid(grid,i,j+1)) cnt+=1;
                }
                
            }
        }
        return cnt;
    }
};
