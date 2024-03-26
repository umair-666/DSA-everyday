// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26

// TLE:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=1;i<=pow(2,31)-1;i++){
            if(count(nums.begin(), nums.end(), i) == 0)
                return i;
        }
        return -1;
    }
};

// Optimised:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Place each positive integer in its correct position
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first missing positive integer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1; // The smallest missing positive integer
            }
        }
        
        return n + 1; // If all positive integers from 1 to n are present, return n + 1
    }
};

