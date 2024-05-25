// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25

class Solution {
    vector<string> dfs(const string& remainingStr,const unordered_set<string>& wordSet,unordered_map<string, vector<string>>& memoization) {
        
      if (memoization.count(remainingStr)) return memoization[remainingStr];
        if (remainingStr.empty()) return {""};
        vector<string> results;
        for (int i = 1; i <= remainingStr.length(); ++i) {
            string currentWord = remainingStr.substr(0, i);
            if (wordSet.count(currentWord)) {
                for (const string& nextWord :
                     dfs(remainingStr.substr(i), wordSet, memoization)) {
                    results.push_back(currentWord +
                                      (nextWord.empty() ? "" : " ") + nextWord);
                }
            }
        }
        memoization[remainingStr] = results;
        return results;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memoization;
        return dfs(s, wordSet, memoization);
    }
};
