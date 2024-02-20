// 268. Missing Number
//  https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

// Approach 1:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n *(n+1))/2;
        int sum = accumulate(nums.begin(), nums.end(),0);
        return total_sum - sum;
    }
};

// Approach 2:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }
};
