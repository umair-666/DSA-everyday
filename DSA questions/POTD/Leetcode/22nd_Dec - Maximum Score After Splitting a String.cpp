// 1422. Maximum Score After Splitting a String
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0, zeros = 0, maxScore = 0;

        // Count the number of ones in the string
        for (char c : s) {
            if (c == '1') ones++;
        }

        // Iterate through the string except the last character
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }

            // Update maxScore for each split
            maxScore = max(maxScore, zeros + ones);
        }

        return maxScore;
    }
};
