// 1160. Find Words That Can Be Formed by Characters
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int len = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<chars.size();i++)
            mp[chars[i]]++;

        for (const string& word : words) {
            unordered_map<char, int> tempFreq(mp);
            bool valid = true;
            
            for (char c : word) {
                if (tempFreq[c] > 0) {
                    tempFreq[c]--;
                } else {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                len += word.size();
            }
        }
        return len;

    }
};
