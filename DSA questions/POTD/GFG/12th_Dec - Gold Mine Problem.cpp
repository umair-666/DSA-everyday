// Gold Mine Problem
// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
    int helper(int r, int c, int n, int m, vector<vector<int>>& M, vector<vector<int>>& dp) {
        if (c >= m) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int ans1 = (c + 1 < m) ? M[r][c + 1] + helper(r, c + 1, n, m, M, dp) : 0;
        int ans2 = (r - 1 >= 0 && c + 1 < m) ? M[r - 1][c + 1] + helper(r - 1, c + 1, n, m, M, dp) : 0;
        int ans3 = (r + 1 < n && c + 1 < m) ? M[r + 1][c + 1] + helper(r + 1, c + 1, n, m, M, dp) : 0;

        dp[r][c] = max({ans1, ans2, ans3});
        return dp[r][c];
    }

public:
    int maxGold(int n, int m, vector<vector<int>>& M) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; ++i) {
            res = max(res, M[i][0] + helper(i, 0, n, m, M, dp));
        }

        return res;
    }
};
