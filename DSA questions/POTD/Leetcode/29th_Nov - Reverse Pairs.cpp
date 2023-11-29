// 493. Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int c = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] > 2*nums[j])
                    c++;
            }
        }
        return c;
    }
};
