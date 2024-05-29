// Geek and its Game of Coins
// https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1

class Solution {
    int helper(int n, int x, int y, vector<int> &dp){
        
        if(n <= 0)  return 0;
        if(dp[n] != -1) return dp[n];
        
        int a = 0, b = 0, c = 0; 
        if(n >= 1)
            a = !helper(n-1,x,y,dp);
        if(n >= x)    
            b = !helper(n-x,x,y,dp);
        if(n >= y)
            c = !helper(n-y,x,y,dp);
        if(a||b||c)
            return dp[n]=1;
        else
            return dp[n]=0;
    }
  public:
    int findWinner(int n, int x, int y) {
         vector<int> dp(n+1,-1);
       return helper(n, x, y, dp);
    }
};
