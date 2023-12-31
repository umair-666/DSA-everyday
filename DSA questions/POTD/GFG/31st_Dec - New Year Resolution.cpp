// New Year Resolution
// https://www.geeksforgeeks.org/problems/good-by-2023/1

class Solution {
    public:
    int solve(int i,int sum,int n,int arr[],vector<vector<int>> &dp){
        if(i<=n && sum!=0 && (sum%20==0 || sum%24==0)) return 1;
        if(i>=n) return 0;

        if(dp[i][sum]!=-1) return dp[i][sum];

        bool notPick=solve(i+1,sum,n,arr,dp);
        bool pick=solve(i+1,sum+arr[i],n,arr,dp);
        return dp[i][sum]=(pick || notPick);
    }
    int isPossible(int n , int arr[]) 
    {
        int sum=0;
        for(int i=0;i<n;i++)   sum+=arr[i];
        if(sum==2024 || sum%20==0 || sum%24==0) return 1;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(0,0,n,arr,dp);   
    }
};
