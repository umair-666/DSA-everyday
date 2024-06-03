// 2486.  Append Characters to String to Make Subsequence
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, longestPrefix = 0;

        while (first < s.length() && longestPrefix < t.length()) {
            if (s[first] == t[longestPrefix]) {
                longestPrefix++;
            }
            first++;
        }
        return t.length() - longestPrefix;
    }
};
