// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20

class Solution {
    int helper(vector<int>& nums, int level, int currentXOR) {
        if (level == nums.size()) 
            return currentXOR;
        int include = helper(nums, level + 1, currentXOR ^ nums[level]);
        int exclude = helper(nums, level + 1, currentXOR);
        
        return include + exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0); // nums, level, current XOR
    }
};
