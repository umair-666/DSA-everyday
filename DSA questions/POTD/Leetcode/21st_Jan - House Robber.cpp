//198.House Robber
//https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21

//Simple Recursion: TLE
class Solution {
    int solve(int i,vector<int>& nums){

        if(i >= nums.size())   return 0;

        int take = nums[i] + solve(i+2,nums);
        int not_take =  0 + solve(i+1, nums);
        return max (take , not_take);
    }
public:
    int rob(vector<int>& nums) {
        return solve(0,nums);
    }
};

//Memoized:
class Solution {
    int solve(int i,vector<int>& nums, vector<vector<int>> &dp){

        if(i >= nums.size())   return 0;

        if(dp[i][i] != -1)  return dp[i][i];

        int take = nums[i] + solve(i+2,nums,dp);
        int not_take =  0 + solve(i+1, nums,dp);

        dp[i][i] = max (take , not_take);
        return dp[i][i];

    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0,nums, dp);
    }
};

//Iterative:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};
