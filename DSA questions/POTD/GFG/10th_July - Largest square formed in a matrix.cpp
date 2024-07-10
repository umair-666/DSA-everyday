// Largest square formed in a matrix
// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

class Solution {
  public:
int maxSquare(int n, int m, vector<vector<int>> mat) {
       vector<vector<int>> dp(n, vector<int>(m,0));
        int maxSize = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <m; j++)
            {
                if( i == 0 || j == 0)
                {
                    dp[i][j] = mat[i][j];
                }
                else if(mat[i][j] == 1)
                {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                
                if(dp[i][j] > maxSize){
                    maxSize = dp[i][j];
                }
            }
        }
        
        return maxSize;
    }
};
