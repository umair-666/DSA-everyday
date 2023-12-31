// 1624. Largest Substring Between Two Equal Characters
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=daily-question&envId=2023-12-31

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), maxi = -1;
        unordered_map<char, int> mp;

        for (int i = 0; i < n; ++i) {
            if (mp.count(s[i])) {
                maxi = max(maxi, i - mp[s[i]] - 1);
            } else {
                mp[s[i]] = i;
            }
        }
        return maxi;
    }
};
