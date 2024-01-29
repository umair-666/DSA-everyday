// Count digit groupings of a number
// https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

class Solution{
    
    int dp[101][901];
    
	int solve(int i, int sum, int n, string& s){
	    if(i >= n) return 1;
	    
	    if(dp[i][sum] != -1) return dp[i][sum];
	    
	    int add = 0;
	    int total = 0;
	    
	    for(int j=i; j<n; j++){
	        add += s[j] - '0';
	        if(add >= sum) total += solve(j+1, add, n, s);
	    }
	    
	    return dp[i][sum] = total;
	}
	public:
	int TotalCount(string str){
	    int n = str.size();
	    memset(dp, -1, sizeof dp);
	    return solve(0, 0, n, str);
	}
};
