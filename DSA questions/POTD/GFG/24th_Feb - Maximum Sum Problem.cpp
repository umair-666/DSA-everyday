// Maximum Sum Problem
//   https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

//Recursive:
class Solution
{
    public:
        int maxSum(int n)
        {
            if(n==0 ||n==1) {
               return n;
           }
            int value1 = (n/2);
            int value2 = (n/3);
            int value3 = (n/4);
            int ans = maxSum(value1) + maxSum(value2) + maxSum(value3);
            return max(ans,n);
        }
};

// Optimised:
class Solution
{
    public:
        int maxSum(int n)
        {
            vector<int> dp(n+1,0);
            int sum = 0;
            for(int i=1;i<=n;i++){
                dp[i] += max(dp[i/2] + dp[i/3] + dp[i/4], i);
            }
            
            return dp[n];
        }
};
