// Distinct occurrences
//   https://www.geeksforgeeks.org/problems/distinct-occurrences/1

class Solution
{
    public:
     int mod = 1000000007;
    int helper(int i, int j, const string& s, const string& t, vector<vector<int>>& dp) {
        // Base cases
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = (helper(i + 1, j + 1, s, t, dp) % mod + helper(i + 1, j, s, t, dp) % mod) % mod;
        } else {
            dp[i][j] = helper(i + 1, j, s, t, dp) % mod;
        }

        return dp[i][j];
    }
    int subsequenceCount(string s, string t)
    {
        int n = s.size(), m= t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return helper(0,0,s,t, dp);
    }
};
