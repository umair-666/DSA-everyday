// 1347.Minimum Number of Steps to Make Two Strings Anagram
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> x; //s_count
        unordered_map<char, int> y; //t_count

        for (char it : s) {
            x[it]++;
        }

        for (char it : t) {
            y[it]++;
        }

        int cnt = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            cnt += abs(x[i] - y[i]);
        }

        return cnt / 2;  
    }
};
