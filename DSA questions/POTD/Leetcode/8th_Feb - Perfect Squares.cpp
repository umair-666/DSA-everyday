// 279. Perfect Squares
//  https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

// TC = O(N*root(N))     SC = O(N)
class Solution {
    int helper(int n, unordered_map<int, int>& memo) {
        if (n == 0) return 0;
        
        if (memo.find(n) != memo.end()) return memo[n];
        
        int minSquares = INT_MAX;
        
        for (int i = 1; i * i <= n; ++i) {
            int squares = helper(n - i * i, memo);
            minSquares = min(minSquares, squares + 1);
        }
        
        memo[n] = minSquares;
        
        return minSquares;
    }
public:
    int numSquares(int n) {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }
};

// Final Code:
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
