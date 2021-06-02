class Solution {
    public:
        int coinChange(vector<int>& coins, int target){
            vector<int> dp(target+1, target+1);
            dp[0] = 0;
            for(int i = 0; i <= target; i++){
                for(int j = 0; j < coins.size(); j++){
                    if(coins[j] <= i){
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            return dp[target] > target ? -1 : dp[target];
        }
    };
