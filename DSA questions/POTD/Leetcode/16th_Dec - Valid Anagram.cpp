// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/?envType=daily-question&envId=2023-12-16

// Approach 1:

class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        if(s==t)
          return true;
        return false;
      }   
};

// Approach 2: Optimised code-

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> mp;

        for(auto c : s)
            mp[c]++;
        
        for(auto x : t)
            mp[x]--;

        for(auto it : mp){
            if(it.second !=0)
                return false;
        }
        return true;

      // OR this line instead of lines 33-37
       // return all_of(mp.begin(), mp.end(), [](const auto& pair) { return pair.second == 0; });
    }
};
