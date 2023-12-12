// 1464. Maximum Product of Two Elements in an Array
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2023-12-12

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int larger = nums[n-1];
        int large = nums[n-2];
        
        return (larger-1) * (large-1);
    }
};

// Python:

// class Solution(object):
//     def maxProduct(self, nums):
//         """
//         :type nums: List[int]
//         :rtype: int
//         """
//         nums.sort()
//         larger = nums[-1]
//         large = nums[-2]
//         return (larger-1) * (large-1)
