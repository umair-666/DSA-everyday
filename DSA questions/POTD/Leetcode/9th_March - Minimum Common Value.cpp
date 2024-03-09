// 2540. Minimum Common Value
// https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

// Brute Force:
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(int num : nums1){
            s.insert(num);
        }

        for(int num : nums2){
            if(s.find(num) != s.end())
                return num;
        }
        return -1;
    }
};

// Optimal two-pointer approach:
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) // If common element found, return it
                return nums1[i];
            else if (nums1[i] < nums2[j]) // Move pointer in nums1
                i++;
            else // Move pointer in nums2
                j++;
        }
        return -1; // No common element found
    }
};
