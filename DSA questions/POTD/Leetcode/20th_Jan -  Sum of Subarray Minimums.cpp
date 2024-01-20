//907. Sum of Subarray Minimums
//https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20



const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            left[i] = (stk.empty()) ? -1 : stk.top();
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            right[i] = (stk.empty()) ? length : stk.top();
            stk.push(i);
        }

        int sum = 0;

        for (int i = 0; i < length; ++i) {
            sum = (sum + static_cast<long long>(nums[i]) * (i - left[i]) * (right[i] - i) % MOD) % MOD;
        }

        return sum;
    }
};
