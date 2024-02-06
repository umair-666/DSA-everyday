// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>> mp;

        for(int i = 0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for(auto it : mp){
            res.push_back(it.second);
        }

        return res;
    }
};
