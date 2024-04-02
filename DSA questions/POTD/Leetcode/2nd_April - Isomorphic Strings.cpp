// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        unordered_map<char,char> mp1; // s->t
        unordered_map<char,char> mp2; // t->s

        for(int i=0;i<n;i++){
            char cs = s[i];
            char ct = t[i];

            // Check if there's a mapping for charS in mp1 and if it maps to the same character in t
            if (mp1.find(cs) != mp1.end()) {
                if (mp1[cs] != ct)
                    return false;
            }
            else if(mp2.find(ct) != mp2.end()){ // If no mapping exists, check if charT is already mapped to some other character in mp2
                return false;
            }
            mp1[cs] = ct;
            mp2[ct] = cs;
        }
            return true;
        }
};
