// Maximize dot product
// https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1

class Solution{
  int solve(int n, int m, int a[], int b[] , int i , int j , int x , vector<vector<int>>& dp){
        
        if(i >= n || j >= m)
            return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int include = 0;
        if(x > 0 && j < m)
            include = 0 + solve(n,m,a,b,i+1,j,x-1,dp);
        
        int exclude = a[i] * b[j] + solve(n,m,a,b,i+1,j+1,x,dp);
        
        return dp[i][j] = max(include,exclude);
    }
public:
	int maxDotProduct(int n, int m, int a[], int b[]) { 
		
		vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,a,b,0,0,n-m,dp);
	} 
};
