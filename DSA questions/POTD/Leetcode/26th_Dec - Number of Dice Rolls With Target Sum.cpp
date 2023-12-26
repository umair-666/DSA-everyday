// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26


int mod = 1000000007;
class Solution {
    int helper(int n, int sides , int target, vector<vector<int>> &dp){
        if (n == 0 && target == 0) 
            return 1;
        if (target < n || n * sides < target) 
            return 0;

        if(dp[n][target] != -1)  return dp[n][target]; 
        
        int ans = 0;

        for(int i=1;i<=sides;i++){
            if(target < i)  break;
            ans = (ans + helper(n-1,sides,target-i, dp) % mod) % mod;
        }

        dp[n][target] = ans;
        return ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        if (n == 0 && target == 0) 
            return 1;
        if (target < n || n * k < target) 
            return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return helper(n, k, target,dp);
    }
};

