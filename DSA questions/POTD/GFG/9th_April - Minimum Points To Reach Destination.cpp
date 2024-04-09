// Minimum Points To Reach Destination
// https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

 class Solution{
    
    int helper(int i, int j, vector<vector<int>>& p, vector<vector<int>>& dp){
        int m = p.size(), n = p[0].size();
        
        if (i >= m || j >= n)
            return INT_MAX;

        if (i == m - 1 && j == n - 1)
            return 1 - p[i][j];
            
        if (dp[i][j] != -1)
            return dp[i][j];
            
        int down = helper(i + 1, j, p,dp); // down
        int right = helper(i, j + 1, p,dp); // right

        int res = max(1, min(down, right) - p[i][j]);
        return dp[i][j] = res;
    }
	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{
	     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
         return helper(0, 0, points,dp);
	} 
};
