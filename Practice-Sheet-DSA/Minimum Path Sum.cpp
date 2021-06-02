class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n+1][m+1];
        for(int i = n-1; i>=0 ; i--){
            for(int j = m-1; j>=0 ; j--){
                if(i == n-1 and j == m-1){ 
                    dp[i][j] = grid[i][j];
                }
                else if(i == n-1){ 
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                else if(j == m-1){ 
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else{  
                    dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
