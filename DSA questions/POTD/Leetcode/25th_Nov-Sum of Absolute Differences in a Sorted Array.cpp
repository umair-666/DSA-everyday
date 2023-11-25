// 1685. Sum of Absolute Differences in a Sorted Array

// Optimised:

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> prefixSum(n), suffixSum(n);
    std::vector<int> result;

    // Calculate prefix sum
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // Calculate suffix sum
    suffixSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    // Calculate absolute differences
    for (int i = 0; i < n; ++i) {
        int leftSum = i * nums[i] - (i > 0 ? prefixSum[i - 1] : 0);
        int rightSum = (i < n - 1 ? suffixSum[i + 1] : 0) - (n - 1 - i) * nums[i];
        result.push_back(leftSum + rightSum);
    }

    return result;
    }
};

// ----------*********------------

//  Brute force: Gives TLE:
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=0;j<nums.size();j++){
                sum += abs(nums[i] - nums[j]);
            }
            result[i] = sum;
        }
        return result;
    }
};

