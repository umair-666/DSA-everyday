// 1897. Redistribute Characters to Make All Strings Equal
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        
        if(n == 1)   return true;

        unordered_map<char,int> mp;
        for(auto it : words){
            for(auto x : it){
                mp[x]++;
            }
        }

    for(auto it : mp){
        if(it.second % n != 0)
            return false;
    }
    return true;
    }
};
