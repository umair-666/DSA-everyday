// 300.. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05

// DP approach : TC = O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        return  *max_element(dp.begin(), dp.end());
        
    }
};

// Uing Binary Search: TC = O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> tails(nums.size(), 0);
        int size = 0;

        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
};
