class Solution {
public:
    
    /* int fib(int n) {
        if(n==0 || n==1) return n;
        int ans = fib(n-1)+fib(n-2);
        return ans;
    } */

    /*
    int top_down_dp(int n,vector<int> &dp){
        if(n==0 || n==1) return n;
        if(dp[n]!=0) return dp[n];
        dp[n] = top_down_dp(n-1,dp)+top_down_dp(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(31,0);
        return top_down_dp(n,dp);
    }
    */
    
     int fib(int n) {
       vector<int> dp(31,0);
       dp[0]=0,dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2];
       }  
         return dp[n];
    }
    
    
    
    
};
