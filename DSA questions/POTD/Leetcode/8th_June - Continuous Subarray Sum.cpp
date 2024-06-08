// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int sum = nums[0];
        int n = nums.size();
        int j, temp;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                if (nums[i] == 0)
                    return true;
            sum += nums[i];
            if (sum % k == 0)
                return true;
            j = 0;
            temp = sum;
            while ((i - j) > 1 and temp >= k) {
                temp -= nums[j++];
                if (temp % k == 0)
                    return true;
            }
        }
        return false;
    }
};
