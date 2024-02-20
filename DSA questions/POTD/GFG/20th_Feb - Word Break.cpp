// Word Break
// https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution
{
     bool wordBreakHelper(const string& s, unordered_set<string>& dictionary) {
        if (s.empty())
            return true; // Base case: empty string can be segmented

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (dictionary.count(prefix) && wordBreakHelper(s.substr(i), dictionary)) {
                return true;
            }
        }

        return false;
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return wordBreakHelper(s, dict);
    }
};
