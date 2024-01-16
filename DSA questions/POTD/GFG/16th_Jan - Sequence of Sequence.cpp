// Sequence of Sequence
// https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

// Approach 1:

class Solution{
    int dp[101][101];
    int solve(int last, int m, int n){
        
        if(n<=0)return 1;
        
        if(dp[last][n]!=-1)return dp[last][n];
        
        int ans = 0;
        
        for(int i=max(1,2*last);i<=m;i++){
            ans+=solve(i,m,n-1);
        }
        
        return dp[last][n] = ans;
    }
public:
    int numberSequence(int m, int n){
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n);
    }
};

// Approach 2:

// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        if(n==0)    return 0;
        
        if(n==1)    return m;
        
        int sum=0;
        
        for(int i=1;i<=m;i++){
            sum+=numberSequence(i/2,n-1);
        }
        return sum;
    }
};
