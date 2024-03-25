// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

// TC: O(N) , SC: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;

        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                // If the element at index 'index' is negative, it means it has appeared before
                v.push_back(index + 1); // add duplicate value
            } else {
                // Mark the element at index 'index' as visited by negating its value
                nums[index] = -nums[index];
            }
        }

        return v;
    }
};

// TLE:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] == nums[j])
                    v.push_back(nums[i]);
            }
        }
        return v;
    }
};
