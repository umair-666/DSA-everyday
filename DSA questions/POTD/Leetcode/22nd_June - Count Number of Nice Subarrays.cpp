// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int currSum = 0, subarrays = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[currSum] = 1;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i] % 2;
            // Find subarrays with sum k ending at i.
            if (prefixSum.find(currSum - k) != prefixSum.end()) {
                subarrays = subarrays + prefixSum[currSum - k];
            }
            // Increment the current prefix sum in hashmap.
            prefixSum[currSum]++;
        }

        return subarrays;
    }
};
