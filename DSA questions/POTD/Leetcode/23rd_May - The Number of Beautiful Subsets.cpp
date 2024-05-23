// 2597. The Number of Beautiful Subsets
// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23

class Solution {
    int countBeautifulSubsets(vector<int>& nums, int difference, int index, int mask) {
        // Base case
        if (index == nums.size())
            return mask > 0 ? 1 : 0;

        // Flag to check if the current subset is beautiful
        bool isBeautiful = true;

        for (int j = 0; j < index && isBeautiful; ++j){
            isBeautiful = ((1 << j) & mask) == 0 || abs(nums[j] - nums[index]) != difference;
        }
        
        int skip = countBeautifulSubsets(nums, difference, index + 1, mask);
        int take;
        if (isBeautiful)
            take = countBeautifulSubsets(nums, difference, index + 1, mask + (1 << index));
        else
            take = 0;

        return skip + take;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }
};
