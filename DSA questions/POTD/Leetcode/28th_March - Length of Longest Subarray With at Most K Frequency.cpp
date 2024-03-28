// 2958. Length of Longest Subarray With at Most K Frequency
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2024-03-28

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> mp;
        
        for (int end = 0; end < nums.size(); end++) {
            mp[nums[end]]++;
            while (mp[nums[end]] > k) {
                start++;
                mp[nums[start]]--;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};
