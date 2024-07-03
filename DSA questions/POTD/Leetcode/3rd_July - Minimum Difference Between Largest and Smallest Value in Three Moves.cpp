// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};
