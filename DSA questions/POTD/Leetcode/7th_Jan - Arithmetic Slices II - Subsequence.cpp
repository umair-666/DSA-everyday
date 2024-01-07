// 446.Arithmetic Slices II - Subsequence
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/?envType=daily-question&envId=2024-01-07

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int diff_int = static_cast<int>(diff);

                dp[i][diff_int] += 1; 

                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    cnt += dp[j][diff_int];
                }
            }
        }

        return cnt;
    }
};
