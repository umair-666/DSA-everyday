// 2610. Convert an Array Into a 2D Array With Conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

// Code 1 : 
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }  

        while(!mp.empty()){
            vector<int> temp;
            for(auto it = mp.begin(); it != mp.end(); ){
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

// Code 2 : 
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<int> freq(nums.size() + 1);
        
        vector<vector<int>> res;
        for (int i : nums) {
            if (freq[i] >= res.size()) {
                res.push_back({});
            }
            
            // Store the integer in the list corresponding to its current frequency.
            res[freq[i]].push_back(i);
            freq[i]++;
        }
        
        return res;
    }
};
