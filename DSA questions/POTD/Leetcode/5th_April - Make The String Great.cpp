// 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

class Solution {
public:
    bool check(char x, char y) {
        return abs(x - y) == 32;
    }

    string makeGood(string s) {
        string ans = "";
        for (char c : s) {
            if (!ans.empty() && check(ans.back(), c)) 
                ans.pop_back();
            else 
                ans += c;
        }
        return ans;
    }
};
