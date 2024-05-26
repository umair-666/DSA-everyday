// Minimum Cost To Make Two Strings Identical
// https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
         int n=x.size();
        int m=y.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int c1=(n-dp[n][m])*costX;
        int c2=(m-dp[n][m])*costY;
        return c1+c2;
    }
};
