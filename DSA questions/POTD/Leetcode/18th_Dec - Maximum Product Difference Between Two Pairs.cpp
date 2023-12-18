// 1913. Maximum Product Difference Between Two Pairs
// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=daily-question&envId=2023-12-18

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int pro1 = nums[n-1] * nums[n-2];
        int pro2 = nums[0] * nums[1];

        return pro1 - pro2;
    }
};
