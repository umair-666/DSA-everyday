//645.Set Mismatch
//https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i:nums)
            mp[i]++;
        
        int rep;
        for(auto it:mp){
            if(it.second == 2)
                rep = it.first;
        }

        int sum = (n*(n+1))/2;
        int nums_sum = accumulate(nums.begin(), nums.end(),0);
        int missing = sum - (nums_sum - rep);

        return {rep,missing};
    }
};
