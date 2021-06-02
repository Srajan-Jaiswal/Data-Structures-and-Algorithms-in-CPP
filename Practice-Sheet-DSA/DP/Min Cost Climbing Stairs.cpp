class Solution {
public:
    int dp[1001];
    int helper(vector<int>& cost, int idx){
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int c1 = cost[idx] + helper(cost, idx+1);
        int c2 = cost[idx] + helper(cost, idx+2);
        dp[idx] = min(c1, c2);
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(helper(cost, 0), helper(cost, 1));
    }
};
