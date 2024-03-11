// 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

class Solution {
    public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        // Iterate order string to append to result
        string result = "";
        for (char c : order) {
            while (mp[c]-- > 0) {
                result += c;
            }
        }

        // Iterate through freq and append remaining letters
        // This is necessary because some letters may not appear in `order`
        for (auto & [c, count] : mp) { 
            while (count-- > 0) {
                result += c;
            }
        }

        return result;
    }
};
