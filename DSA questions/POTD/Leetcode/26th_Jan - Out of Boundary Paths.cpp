// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

//Approach 1 : (TLE)

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       
       int i = startRow, j = startColumn;
        if(i < 0 || j < 0 || i >= m || j >= n) return 1; //moved out of box;

        if(maxMove == 0)    return 0; //maxMoves finished

        return  findPaths(m,n,maxMove - 1,startRow, startColumn - 1) + 
                findPaths(m,n,maxMove - 1,startRow - 1, startColumn) + 
                findPaths(m,n,maxMove - 1,startRow, startColumn + 1) + 
                findPaths(m,n,maxMove - 1,startRow + 1, startColumn);

    }
};

// Approach 2: Memoized

class Solution {
    const int M = 1e9 + 7;
private:
    int findPaths(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) return 0;
        if (dp[i][j][N] != -1) return dp[i][j][N];

        dp[i][j][N] = (
            (findPaths(m, n, N - 1, i - 1, j, dp) + findPaths(m, n, N - 1, i + 1, j, dp)) % M +
            (findPaths(m, n, N - 1, i, j - 1, dp) + findPaths(m, n, N - 1, i, j + 1, dp)) % M) % M;

        return dp[i][j][N];
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
        return findPaths(m, n, N, i, j, dp);
    }
};
