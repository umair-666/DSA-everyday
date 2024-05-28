// Minimum cost to fill given weight in a bag
// https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

class Solution {
  public:
  int solve(int n, int w, vector<int> &cost, vector<int> &dp) {
        if(dp[w] != 0) return dp[w];
        int ans = INT_MAX;
        if(w <= n && cost[w-1] != -1) ans = cost[w-1];
        for(int i = w-1; i >= (w+1)/2; i--) {
            int tmp1 = solve(n, i, cost, dp);
            int tmp2 = solve(n, w-i, cost, dp);
            if(tmp1 == INT_MAX || tmp2 == INT_MAX) continue;
            ans = min(ans, tmp1+tmp2);
        }
        return dp[w] = ans;
    }
    int minimumCost(int n, int w, vector<int> &cost) {
         vector<int> dp(w+1, 0);
        int ans = solve(n, w,cost,dp);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};
