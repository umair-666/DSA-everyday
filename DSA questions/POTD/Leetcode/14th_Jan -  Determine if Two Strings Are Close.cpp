// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //sTep 1:
        if(word1.size() != word2.size())    return false;

        //step 2:
        unordered_set<char> set1(word1.begin(), word1.end());
        unordered_set<char> set2(word2.begin(), word2.end());

        if(set1 != set2)   return false;
        
        //step3
        vector<int> counts1(26, 0);
        vector<int> counts2(26, 0);

        // Count occurrences of each lowercase alphabet in word1
        for (char c : word1) {
            if (islower(c)) {
                counts1[c - 'a']++;
            }
        }

        // Count occurrences of each lowercase alphabet in word2
        for (char c : word2) {
            if (islower(c)) {
                counts2[c - 'a']++;
            }
        }

        // Sort the counts
        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        // Check if the sorted counts are equal
        return counts1 == counts2;
    }
};
