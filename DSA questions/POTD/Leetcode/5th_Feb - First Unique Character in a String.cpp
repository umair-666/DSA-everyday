// 387. First Unique Character in a String
//  https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;

        for(char c : s)
            mp[c]++;

        for(int i=0;i<s.size();i++){
            char x = s[i];
            if(mp[x] == 1)
                return i;
        }

        return -1;
    }
};
