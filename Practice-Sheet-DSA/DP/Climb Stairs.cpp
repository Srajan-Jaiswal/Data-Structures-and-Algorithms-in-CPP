class Solution {
public:
    int dp[46];
    int memo(int n){
        if(n==0)return 1;
        if(n<0) return 0;
        if(dp[n]!=0) return dp[n];
        dp[n] = memo(n-1)+memo(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        memset(dp,0,sizeof(dp)); 
        return memo(n);
    }
};
