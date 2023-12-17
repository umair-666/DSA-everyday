// Max Sum without Adjacents
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

// Memoized solution:

class Solution{
    int helper(int i , int n, int *arr, vector<int> &dp){
        
        if(i >= n)   return 0;
        
        if(dp[i] != -1) return dp[i];
        int include = 0, exclude = 0;
        
        include = arr[i] + helper(i+2, n, arr,dp);
        exclude = helper(i+1,n,arr,dp);
        
        return dp[i] = max(include , exclude);
        
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n+2,-1);
	    return helper(0,n,arr,dp);
	    
	}
};

// Tabulated solution:

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n+2,0);
        
        for(int i=n-1;i>=0;i--){
            int include=0;
            int exclude=0;
            
            include=arr[i]+dp[i+2];
            exclude=dp[i+1];
            
            dp[i]=max(include,exclude);
            
        }
        return dp[0];
	}
};
