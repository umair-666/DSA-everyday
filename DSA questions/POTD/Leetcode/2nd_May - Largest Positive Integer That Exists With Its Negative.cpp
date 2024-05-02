// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> neg;
      
        for (int num : nums) {
            if (num < 0)
                neg.insert(num);
        }
        
        int res = -1;
        
        for (int num : nums) {
            if (num > res && neg.contains(-num))
                res = num;
        }
        
        return res;
    }
};
