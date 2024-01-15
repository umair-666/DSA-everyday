// Grinding Geek
// https://www.geeksforgeeks.org/problems/grinding-geek/1

class Solution{
    public:
     int fun(int i,int total,vector<int> &cost,int n,vector<vector<int>> &dp){   
        
        if(i==(n-1) || total==0){
            if(total>=cost[i])
                return 1;
                
            return 0;
        }
        
        if(dp[i][total]!=-1)  return dp[i][total];
        
        int t=0,nt=0;
        if(cost[i]<=total){
            t=1+fun(i+1,total-cost[i]+floor(0.90*cost[i]),cost,n,dp);
        }
        nt=fun(i+1,total,cost,n,dp);
        
        return dp[i][total]=max(t,nt);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {   
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return fun(0,total,cost,cost.size(),dp);
    }
};
