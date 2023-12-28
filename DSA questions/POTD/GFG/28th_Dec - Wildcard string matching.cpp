// Wildcard string matching
// https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1

// Tabulation Approach:

class Solution {
public:
    bool match(string wild, string pattern) {
        int n = wild.size();
        int m = pattern.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            if (wild[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (wild[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};
***********----------*************

// Memoization Approach:

class Solution{
    
       int f(int i ,int j,string &wild, string &pattern,vector<vector<int>> &dp){
        
        if(i<0 && j<0)  return 1;
        if(i<0 && j>=0) return 0;
        if(j<0 && i>=0){
            for(int s = 0;s<i;s++){
                if(wild[s] != '*')
                    return 0;
            }
            return 1;
        }
        
        if(dp[i][j] != -1)  return dp[i][j]; //check
        
        if(wild[i] == pattern[j] || wild[i] == '?')
            return dp[i][j] = f(i-1,j-1,wild,pattern, dp); //store
        else if(wild[i] == '*')
            return dp[i][j] = f(i-1,j,wild,pattern,dp) | f(i,j-1,wild,pattern,dp); //store
        else
            return 0;
    }
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n, vector<int> (m, -1)); //declare
        return f(n-1,m-1,wild,pattern ,dp);
    }
};
