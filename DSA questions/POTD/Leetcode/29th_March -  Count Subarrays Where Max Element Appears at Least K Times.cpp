// 2962.  Count Subarrays Where Max Element Appears at Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0, start = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == maxi) {
                k--;
            }
            while (!k) {
                if (nums[start] == maxi) {
                    k++;
                }
                start++;
            }
            ans += start;
        }
        return ans;
    }
};
