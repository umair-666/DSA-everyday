// Reach the Nth point
// https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1

//Tip : Fibonacci in disguise

class Solution{
	public:
	int mod = 1e9+7;
		int nthPoint(int n){
		    
		    vector<int> dp(n+1,0);
		    dp[1] = 1;
		    dp[2] = 2;
		    dp[3] = 3;
		    for(int i=4;i<=n;i++){
		        dp[i] = (dp[i-1] + dp[i-2]) % mod;
		    }   
		
		return dp[n]%mod;
	}
};
