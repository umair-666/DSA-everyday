// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

// Brute Force:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v, x;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i] == nums2[j])
                    v.push_back(nums1[i]);
            }
        }

        set<int> s(v.begin(),v.end());
        for(int it : s)
            x.push_back(it);
        return x;
    }
};

// Optimised:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2) {
            if (s.count(num)) {  // Check if num is present in set
                result.push_back(num);
                s.erase(num); // Remove num from set to handle duplicates
            }
        }

        return result;
    }
};
