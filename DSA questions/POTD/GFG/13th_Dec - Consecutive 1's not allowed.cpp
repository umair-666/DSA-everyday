// Consecutive 1's not allowed
// https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
// Tip : This question is a Fibbonacci Series in disguise

class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    //fibbonacci in disguise
	    int  mod = 1e9+7;
	    vector<ll> dp(n+1,0);  // 0 based indexing
	    dp[1] = 2;
	    dp[2] = 3; 	   
	    // dp[3] = 5; 
	    // dp[4] = 8;

	    for(int i = 3;i <= n;i++){
	        dp[i] = (dp[i-1] + dp[i-2]) % mod;
	    }
	    
	    return dp[n] % mod;
	}
};
