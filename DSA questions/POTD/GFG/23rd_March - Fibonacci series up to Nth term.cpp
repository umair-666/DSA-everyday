// Fibonacci series up to Nth term
// https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

class Solution {
  public:
    vector<int> Series(int n) {
        int mod = 1e9+7;
        vector<int> dp(n+1);
        
        dp[0] = 0, dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        
        return dp;
    }
};
