// 3005. Count Elements With Maximum Frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int maxi = INT_MIN;
        for(auto it : mp){
            if(it.second > maxi)
                maxi = it.second;
        }

        int count = 0;
        for(auto it : mp){
            if(it.second == maxi)
                count +=maxi;
        }

        return count;
    }
};
