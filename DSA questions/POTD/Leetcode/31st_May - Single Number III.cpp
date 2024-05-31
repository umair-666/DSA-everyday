// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31 /

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> pairs;
        unordered_map<int,int> mp;
        for(int  n   : nums){
            mp[n]++;
        }

        for(auto it : mp){
            if(it.second == 1)
            pairs.push_back(it.first);
        }
        return pairs;
    }
};

